#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,a,b;cin>>n>>a>>b;
    if((b-a)%2==0){
        cout<<(b-a)/2<<endl;
        return 0;
    }
    ll buf1=a-1+(b-a+1)/2,buf2=(n-b)+(b-a+1)/2;
    ll res=min(buf1,buf2);
    cout<<res<<endl;
}