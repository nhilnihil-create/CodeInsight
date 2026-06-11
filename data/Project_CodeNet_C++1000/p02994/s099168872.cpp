#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n,l;
    cin>>n>>l;
    int sum = 0;
    int MIN=1e6,aa=1e6;
    rep(i,n){
        sum += (l+i);
        if(MIN>abs(l+i)) aa=i;
        MIN = min(MIN,abs(l-1+i));
    }
    // cout<<MIN<<" "<<sum<<endl;
    cout<<sum-(l+aa)<<endl;
    return 0;

}
