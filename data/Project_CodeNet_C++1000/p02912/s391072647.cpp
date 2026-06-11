#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n,m;
   cin>>n>>m;
   priority_queue<ll> q;
   for(int i=0;i<n;i++)
   {
       ll temp;
       cin>>temp;
       q.push(temp);
   }
   while( m--)
   {
       ll top = q.top();
       q.pop();
       top = top/2;
       q.push(top);
   }
   ll ans =0;
   while( !q.empty() )
   {
       ans += q.top();
       q.pop();
   }
   cout<<ans;
}