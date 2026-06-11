#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll mod=1e9+7;
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{

  int n;
  cin>>n;
  vector<pair<int,int> >v;
  for(int i=0;i<n;i++)
  {
      int a,b;
      cin>>a>>b;
      v.pb(mp(b,a));
  }
  int f=1;
  ll sum=0;
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
      sum+=v[i].ss;
      if(sum>v[i].ff)
      {
          f=0;
          break;
      }
  }
  if(f)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;






}




















































