#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
ll n,x,t;
cin>>n>>x>>t;
if(n%x==0)
cout<< (n/x)*t <<endl;
else
cout<< (n/x+1)*t <<endl;
}
