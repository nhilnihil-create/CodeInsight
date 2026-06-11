#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  int pos=1;
  for(int i=n-2;i>=0;i--){
  	if(nos[i]<=nos[i+1])continue;
    if(nos[i]-1<=nos[i+1]){nos[i]-=1;continue;}
    pos=0;break;
  }
  if(pos==1)cout<<"Yes";
  else cout<<"No";
}