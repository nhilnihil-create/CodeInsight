/*
    *****
    @Author: Harith Insider
    *****
*/
#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve()
{
    ll x1,x2,t1,t2,t;
    cin>>x1>>t1>>x2>>t2>>t;
    ll a=abs(x1-x2);
    ll b=(t1-t2)*t;
  if(a<=b)
    cout<< "YES" << endl;
  else
    cout << "NO" << endl;
}
int main()
{
    fastio;
    solve();
}
