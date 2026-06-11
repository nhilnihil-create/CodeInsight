#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++) 
#define S(v) sort(v.begin(),v.end());


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c, k;
    cin>>a>>b>>c>>k;
    while(b<=a){
        b *=2;
        k--;
    }
    while(c<=b){
        c*=2;
        k--;
    }
    cout<<(k>=0?"Yes":"No");
    

}