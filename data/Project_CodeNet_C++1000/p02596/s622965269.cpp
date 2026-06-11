#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int n;cin>>n;
  	int ans =0, c=0;
  	for(int i=0; i<=1000000; i++){
    	c+=7;
      	c%=n;c*=10;
      	ans++;
      	if(c==0){
        	break;
        }
    }
  	if(c==0)cout<<ans<<"\n";
  	else cout<<-1<<"\n";
}