//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}
int main()
{
  ios;
  int n;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];

  }
  sort(a,a+n);
  for(int i=0;i<n;i++)
  {
      a[i+1]=(a[i]+a[i+1])/2.0;
  }
  cout<<a[n-1]<<endl;





}
//Alhamdulillah










