#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  vector<long long >pos(n+1,0);
  for(int i=0;i<n;i++)pos[nos[i]]++;
  //sum up everyone remove mine and then add with -1 
  long long sumofc2 = 0;
  for(int i=1;i<=n;i++){
  if(pos[i]>1)sumofc2+=((pos[i])*(pos[i]-1))/2;
  }
  long long tot;
  for(int i=0;i<n;i++){
  	tot=0;
    if(pos[nos[i]]>1){
      tot=sumofc2 - (pos[nos[i]]*(pos[nos[i]]-1))/2 + ((pos[nos[i]]-1)*(pos[nos[i]]-2))/2;
      cout<<tot<<'\n';
    }
    else cout<<sumofc2<<'\n';
  }
}