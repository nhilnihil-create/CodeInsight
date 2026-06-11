#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >mon(n+1,0),hero(n,0);
  for(int i=0;i<n+1;i++){
  	cin>>mon[i];
  }
  for(int i=0;i<n;i++)cin>>hero[i];
  long long num=0;
  for(int i=0,change;i<n;i++){
  	change=min(mon[i],hero[i]);
  	num+=change;
  	change = min(mon[i+1],hero[i]-change);
  	num+=change;
  	mon[i+1]-=change;
    
      
  }
  cout<<num;
}