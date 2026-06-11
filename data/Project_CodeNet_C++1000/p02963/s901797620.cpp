#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll s;cin>>s;
    if(s==(1e+18)){
        cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<1000000000<<endl;
        return 0;
    }
    ll x2=1e+9,y2=1;
    ll y3=s/(1000000000),x3=s%(1000000000);
    x3=1000000000-x3;y3++;
    cout<<0<<" "<<0<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
}