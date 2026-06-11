#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/rope>
#define endl '\n'
#define int long long
using namespace std;
using namespace __gnu_cxx;
typedef long long LL;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
signed main(){
    int T1,T2,A1,A2,B1,B2;
    cin>>T1>>T2>>A1>>A2>>B1>>B2;
    if(A1*T1+A2*T2 == B1*T1+B2*T2) { puts("infinity");return 0; }
    A1*=T1; A2*=T2; B1*=T1; B2*=T2;
    if(A1+A2>B1+B2) { swap(A1,B1); swap(A2,B2); }
    if(A1>B1){
        int r = (A1-B1)/(B1+B2-A1-A2);
        int res = 2*r;
        if((A1-B1)%(B1+B2-A1-A2)) res++;
        cout<<res<<endl;
    }else puts("0");
    return 0;
}
