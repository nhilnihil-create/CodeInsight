#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;  

int main()
{
  string s;
  cin>>s;
  int n=s.length();
  ll sum=0;
  int i=0;
  while(i<n)
  {
    ll cnt1=0,cnt2=0;
    while(i<n&&s[i]=='<')
    {
      cnt1++;
      i++;
    }
    while(i<n&&s[i]=='>')
    {
      cnt2++;
      i++;
    }

    if(cnt1>cnt2)
    {
      cnt2--;
    }
    else
    {
      cnt1--;
    }
    sum+=(cnt2*(cnt2+1)/2);
    sum+=(cnt1*(cnt1+1)/2);
  }
  cout<<sum<<endl;
}