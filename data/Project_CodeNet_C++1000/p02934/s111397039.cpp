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
  ll a[n];
  ll gcd=0,k=1,d=0,lcm=1;
  double ans=0;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
      ans+=1.0/(a[i]*1.0);

  }
  cout<<(1.0/ans*1.0)<<endl;




}
//Alhamdulillah









