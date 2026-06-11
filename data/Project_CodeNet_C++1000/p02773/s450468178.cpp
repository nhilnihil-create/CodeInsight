#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)

int main()
{

  int n,i;
  cin>>n;
  map<string,int> mp;
  vector< pair<int,string> > v;
  for(i=0;i<n;i++)
  {
      string s;
      cin>>s;
      mp[s]++;

  }
  map<string,int>:: iterator it;
  for(it=mp.begin();it!=mp.end();it++)
  {
      string a;
      int b;
      a=it->first;
      b=it->second;
      v.push_back(make_pair(b,a));

  }
  int len=v.size();
  set<string> st;
  sort(v.begin(),v.end());
  int t=v[len-1].first;


  for(i=len-1;i>=0;i--)
  {
      //cout<<v[i].first<<' '<<v[i].second<<endl;
      if(v[i].first==t)
      {
          st.insert(v[i].second);
      }
  }

  set<string>:: iterator itt;
  for(itt=st.begin();itt!=st.end();itt++)
  {
      cout<<*itt<<endl;
  }

}




