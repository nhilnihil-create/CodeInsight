//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("avx,avx2,fma,sse,sse2")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    if((b-a)%2==0)cout<<(b-a)/2<<endl;
    else cout<<min((a-1)+((b-a)+1)/2,(n-b)+(n-(a+(n-b))+1)/2)<<endl;

}
