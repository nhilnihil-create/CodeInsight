#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n; cin>>n;
  vector<pair<int,int>>v(n);
  for(int i=0;i<n;i++)
      cin>>v[i].first>>v[i].second;
  int cnt=0;
  for(int i=0;i<n-2;i++)
  {
     if(cnt==3)
      break;
    
   else if(v[i].first==v[i].second && v[i+1].first==v[i+1].second && v[i+2].first==v[i+2].second) {cnt=3;break;}
    
    else cnt=0;
  }
  
 if(cnt==3){cout<<"Yes"<<endl;}
 else {cout<<"No"<<endl;}
  return 0;
}