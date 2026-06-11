#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
const int N = 2e5 +10 ;
int n,q;
LL a[N] ;
LL sum = 0 ;
int main()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
   // freopen("ch.inp","r",stdin) ;
    cin >> n ;
    FOR(i,1,n) cin >> a[i] , sum^= a[i];
    FOR(i,1,n) cout << (sum ^ a[i]) <<" ";


}
