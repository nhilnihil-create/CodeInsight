using namespace std;
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
void solve()
{
ll n,k;
cin>>n>>k;
vector<ll> a(n),v(n,-1);
for (int i = 0; i < n; i++)
{
    cin>>a[i];
    a[i]--;
}
int cur=0;
ll cnt=0;
while (true)
{
 if(v[cur]!=-1||cnt==k)
 break;
v[cur]=cnt;
cur=a[cur];
cnt++;
}
if (k>cnt)
{
    k=k-v[cur];
    cnt-=v[cur];
    k=k%cnt;
    for (int i = 0; i < k; i++)
    {
        cur=a[cur];
    }
}
cout<<cur+1<<endl;
}
int main()
{
     
FASTIO
 long long int t;
 t=1;
 while(t--)
  solve();
  return 0;
}
