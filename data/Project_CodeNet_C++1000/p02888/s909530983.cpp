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
int minn=10000000;
int maxn=-1;
int ans= 0;

void b_search(int left, int right, int x){
    int mid = (right + left)/2;
    if(right == left){
        ;
    }
    else if(l[mid] < x){    
        b_search(mid+1,right,x);
        maxn = max(maxn,mid);
    }
    else{
        minn = min(minn,mid);
        b_search(left, mid,x);
    }
}

int main(){
    cin >> n;
    rep(i,n) cin >> l[i];
    sort(l,l+n);
    rep(i,n-2){
        for(int j=i+1;j<n-1;j++){
            int a = l[i];
            int b = l[j];
            minn=100000000;
            maxn=-1;
            b_search(0,n,a+b);
            // cout << minn << " " << maxn << endl;
            int idx = maxn;
            ans += maxn - j;
        }
    }
    cout << ans << endl;


return 0;
}