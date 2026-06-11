#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#include<tuple>




using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << setprecision(7) << (x) << endl;

struct idxx{
    int a;
    int b;
    int c;
};

long double pi = 3.14159265359;
map<tuple<int,int,int>,int> mp;

int n;
int l[10000];
// int minn=10000000;
// int maxn=-1;
int ans= 0;

// void b_search_process(int left, int right, int x){
//     int mid = (right + left)/2;
//     if(right == left){
//         ;
//     }
//     else if(l[mid] < x){    
//         b_search_process(mid+1,right,x);
//         maxn = max(maxn,mid);
//     }
//     else{
//         minn = min(minn,mid);
//         b_search_process(left, mid,x);
//     }
// }

// void b_search(int left, int right, int x){
//     minn=100000000;
//     maxn=-1;
//     b_search_process(left,right,x); //これした後にminnの値が変わってないなら、lはx以上の要素がない。maxnが変わってないなら、lはx未満の要素なし
//     if(minn == 100000000) minn = n;
    
// }

tuple<int ,int> bi_search(int left, int right, int x){
    int minn=right;
    int maxn=left-1;
    while(left!=right){
        int mid = (right+left)/2;
        if(l[mid] < x){
            maxn = max(maxn,mid);
            left = mid+1;
        }
        else{
            minn = min(minn,mid);
            right = mid;
        }
    }
    tuple<int ,int> t = make_tuple(maxn,minn);

    return t;
}

int main(){
    cin >> n;
    rep(i,n) cin >> l[i];
    sort(l,l+n);
    rep(i,n-2){
        for(int j=i+1;j<n-1;j++){
            int a = l[i];
            int b = l[j];
            tuple<int ,int> t = bi_search(0,n,a+b);
            // cout << get<0>(t) << " " << get<1>(t) <<  endl;
            // int idx = maxn;
            // int idx = cmin - 1;
            // ans += cmax - j;
            // ans += idx - j;
            ans += get<0>(t) - j;
        }
    }
    cout << ans << endl;


return 0;
}