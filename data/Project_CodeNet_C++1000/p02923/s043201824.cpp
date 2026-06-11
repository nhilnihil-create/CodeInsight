#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >h(n,0);
  for(int i=0;i<n;i++)cin>>h[i];
  int maxi=1,curr=1;
  for(int i=1;i<n;i++){
  	if(h[i]<=h[i-1])curr++;
    else{
    	maxi = max(maxi,curr);
      curr=1;
    }
  }
  maxi = max(maxi,curr);
  cout<<maxi-1;
}