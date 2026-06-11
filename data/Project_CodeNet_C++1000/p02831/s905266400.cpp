#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

ll gcd(ll a , ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<lcm(a,b);
   
    return 0;
}
