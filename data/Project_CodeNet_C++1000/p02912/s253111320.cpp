#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) (m*n)/GCD(m,n)
# define mod 1000000007

int main()
{
    IOS;
    ll i,j,k,t,n,sum=0,prod=1,flag=0,mark=0,marker=0,m;
    cin >> n >> m;
    ll a[n];
    priority_queue<ll> q;
    for(i=0;i<n;i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
   for(i=0;i<m;i++)
   {
       ll x = q.top();
       q.pop();
       x/=2;
       q.push(x);
   }
   while(!q.empty())
   {
       sum+=q.top();
       q.pop();
   }
   cout << sum << endl;
}
