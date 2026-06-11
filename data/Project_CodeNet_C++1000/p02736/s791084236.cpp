#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

bool nCr_odd(int n,int r){
    return (n&r)==r;
}

signed main(){
    int n; cin >> n;
    string s; cin >> s;
    if(n==2){
        int x=s[0]-'0',y=s[1]-'0';
        cout << abs(x-y) << endl;
        return 0;
    }
    int s1[n],s2[n-1];
    rep(i,n) s1[i]=s[i]-'0';
    bool exist1=0;
    rep(i,n-1){
        s2[i]=abs(s1[i+1]-s1[i]);
        if(s2[i]==1) exist1=1;
    }
    if(exist1){
        rep(i,n-1){
            if(s2[i]==2) s2[i]=0;
        }
        int odd=0;
        rep(i,n-1){
            odd+=nCr_odd(n-2,i)*s2[i];
        }
        odd%=2;
        if(odd) cout << 1 << endl;
        else cout << 0 << endl;
    }else{
        rep(i,n){
            if(s2[i]==2) s2[i]=1;
        }
        int odd=0;
        rep(i,n-1){
            odd+=nCr_odd(n-2,i)*s2[i];
        }
        odd%=2;
        if(odd) cout << 2 << endl;
        else cout << 0 << endl;
    }
}

