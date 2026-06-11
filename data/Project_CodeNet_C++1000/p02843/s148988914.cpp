#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >pos(n+1,0);
  pos[0]=1;
  for(int i=1;i<=n;i++){
  	for(int coin=100;coin<106;coin++){
    		if(i-coin >= 0)pos[i]=pos[i]|pos[i-coin];
    }
  }
  cout<<pos[n];
}