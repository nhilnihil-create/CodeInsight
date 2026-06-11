#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    rep(i,30)if((1<<i)==n){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    rep(i,2){
        cout<<i+1<<' '<<i+2<<endl;
        cout<<i+1+n<<' '<<i+2+n<<endl;
    }
    cout<<3<<' '<<n+1<<endl;
    int now=4;
    for(;now<n;now+=2){
        cout<<now<<' '<<now+1<<endl;
        cout<<now+1<<' '<<n+1<<endl;
        cout<<now+n<<' '<<now+1+n<<endl;
        cout<<n+1<<' '<<now+n<<endl;
    }
    if(now==n){
        int lsb=n&(-n);
        int tmp=n^lsb^1;
        cout<<n<<' '<<lsb+n<<endl;
        cout<<tmp<<' '<<2*n<<endl;
    }

}