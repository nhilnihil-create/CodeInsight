#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  int maxi=0;
  int count_maxi=0;
  int second_maxi=0;
  for(int i=0;i<n;i++)maxi = max(maxi,nos[i]);
  for(int i=0;i<n;i++)if(nos[i]==maxi)count_maxi++;
  if(count_maxi==1){
  	for(int i=0;i<n;i++)if(nos[i]<maxi)second_maxi = max(second_maxi,nos[i]);
  }
  if(count_maxi>1){
  	for(int i=0;i<n;i++)cout<<maxi<<'\n';
  }
  else{
  	for(int i=0;i<n;i++){
    	if(nos[i]==maxi)cout<<second_maxi;
      else cout<<maxi;
      cout<<'\n';
    }
  }
}