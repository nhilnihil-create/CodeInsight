#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n+1,0);
    rep(i,n){
        cin>>a[i+1];a.push_back(a[i+1]);
    }
    rep(i,2*n-1){
        if(i%2==1)a[i+1]=a[i]-a[i+1];
        else a[i+1]+=a[i];
    }
    rep(i,n){
        ll res=a[n+i]-a[i];
        res=abs(res);
        cout<<res<<" ";
    }
    cout<<endl;
}