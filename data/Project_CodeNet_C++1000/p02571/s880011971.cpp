#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

  string S,T;
  cin>>S>>T;
  int ans=T.size();
  int s=S.size();
  int t=T.size();
  for(int i=0;i<=s-t;i++)
  {
    int d=0;
    for(int j=0;j<t;j++)
    {
      if(S[i+j]!=T[j])
      {
        d++;
      }
    }
    ans=min(ans,d);
  }
  cout<<ans;



	return 0;
}