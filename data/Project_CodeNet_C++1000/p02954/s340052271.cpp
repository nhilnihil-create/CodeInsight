#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;

#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

/*
任意の場所にどのマスの子供が集まるか
*/

int main()
{
  string S;cin>>S;
  ll n = S.size();
  
  vector<ll> a(n+1);
  ll i = 0;
  ll count=0;
  ll num = 0;//何個に別れるか
  while (i<n)
  {
    count=0;
    while (S[i]==S[i+1])
    {
      i++; 
      count++;
    }
    a[num]=count+1;
    i++;
    num++;
  }
  //for (int i=0;i<num;i++)
   // cout<<a[i]<<" ";
  
  vector<ll> ans(n+1,0);//答えを格納する配列
  
  ll now=0;
  for (int i=0;i<num;i+=2)
  { 
    if (a[i]%2!=a[i+1]%2)
    { 
      if (max(a[i],a[i+1])%2==0)
      {
        ans[now+a[i]+1]=(a[i]+a[i+1])/2+1;
        ans[now+a[i]]=(a[i]+a[i+1])/2;
        if (a[i]<a[i+1]) swap(ans[now+a[i]+1],ans[now+a[i]]);
      }
      else{
       ans[now+a[i]+1]=(a[i]+a[i+1])/2;
       ans[now+a[i]]=(a[i]+a[i+1])/2+1;
       if (a[i]<a[i+1]) swap(ans[now+a[i]+1],ans[now+a[i]]);
      }
    }
    else
    {
      ans[now+a[i]]=(a[i]+a[i+1])/2;
      ans[now+a[i]+1]=(a[i]+a[i+1])/2;
    }
    now += a[i]+a[i+1];
  }
  
  for (int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
}