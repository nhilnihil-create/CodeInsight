#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t,sum=0;
  string s;
  map<string,int> m;
  map<string, int>::iterator itr; 
  cin >> t;
  for(int i=0;i<t;i++)
  {
    cin >> s;
    sort(s.begin(),s.end());
    if(m[s]==0)  m[s]=1;
    else m[s]++;
  }
  for(itr = m.begin();itr!=m.end();itr++)
  {
    ll n = itr->second -1;
    sum +=  ((n*(n+1))/2);
  }
  cout <<sum;
}