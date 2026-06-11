#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  vector<int> alphabets(26,0);
  int maxal=0;
  map<string,int> m;
  for(int i=0;i<N;i++)
  {
    string S;cin>>S;
    m[S]++;
    maxal=max(maxal,m[S]);
  }
  for(auto p : m)
  {
    if(p.second==maxal)cout<<p.first<<endl;
  }
}