#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define ff first
#define ss second

typedef pair<int, int> ii;

vector <int> nums;
vector <ii> tree;



struct ctnr{
    int mxa, mxb;
};

ii giveMe(ii x, ii y)
{
    ii ret;
    ret.ff = max(x, y).ff;
    ret.ss = max(max(x, y).ss, min(x, y).ff);
    return ret;
}

void buildtree(int node, int s, int e)
{
    if(s==e){
        tree[node] = {nums[s], -1};
        return;
    }
    buildtree(node*2, s, (s+e)/2);
    buildtree(node*2 + 1, (s+e)/2 + 1, e);

    tree[node] = giveMe(tree[node*2], tree[node*2 + 1]);
}

ii query(int node, int s, int e, int rs, int re)
{
    if(max(s, rs)>min(e, re)) return {-1, -1};
    if(s>=rs && e<=re) return tree[node];
    else return giveMe(query(node*2, s, (s+e)/2, rs, re), query(node*2+1, (s+e)/2 + 1, e, rs, re));
}

int main()
{
    int n;
    scanf("%d", &n);

    nums.resize(n + 3);
    tree.resize(n * 3 + 15);

    for(int i = 0; i<n; i++){
    	sf("%d", &nums[i+1]);
    }

    buildtree(1, 1, n);
    long long ans = 0;

    for(int i = 1; i<=n; i++){
        //find x1
        int x1 = 0, x2 = 0;
        int lo = 1, hi = i - 1, mid;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            ii x = query(1, 1, n, mid, i);
            if(x.ff == nums[i]) hi = mid - 1;
            else{
                if(x.ss==nums[i]) x1 = mid;
                lo = mid + 1;
            }
        }

        // find x2
        lo = 1, hi = x1 - 1, mid;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            ii x = query(1, 1, n, mid, i);
            if(x.ss == nums[i]) hi = mid - 1;
            else{
                if(x.ss > nums[i]) x2 = mid;
                lo = mid + 1;
            }
        }

        //find y1
        int y1 = 0, y2 = 0;
        lo = i + 1, hi = n, mid;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            ii x = query(1, 1, n, i, mid);
            if(x.ff == nums[i]) lo = mid + 1;
            else{
                if(x.ss==nums[i]) y1 = mid;
                hi = mid - 1;
            }
        }

        // find y2
        lo = y1, hi = n, mid;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            ii x = query(1, 1, n, i, mid);
            if(x.ss == nums[i]) lo = mid + 1;
            else{
                if(x.ss > nums[i]) y2 = mid;
                hi = mid - 1;
            }
        }
        //printf("%d\n", nums[i]);
        //printf("%d %d\n", nums[x1], nums[x2]);
        //printf("%d %d\n", nums[y1], nums[y2]);

        long long int delta = 0;

        if(!x1 && !y1) delta += 0;
        if(y1){
            if(y2) delta += (y2 - y1) * (i - x1);
            else delta += (n - y1 + 1) * (i - x1);
        }

        //cout<<"MID-DELTA: "<<delta<<endl;

        if(x1){
            if(!y1) y1 = n + 1;
            if(x2) delta += (x1 - x2) * (y1 - i);
            else delta += (x1) * (y1 - i);
        }

        //cout<<"DELTA: "<<delta<<endl;

        ans += (delta * nums[i]);

    }

    printf("%lld\n", ans);


    return 0;

}
