#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

    ll a,b,n;
ll f(ll x)
{
    return a*x/b - a*(x/b);
}

void test_case()
{
    cin>>a>>b>>n;
    if(n>=b) {
        cout<<f(b-1);
    } else {
        // n < b
        cout<< f(n);
    }
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
