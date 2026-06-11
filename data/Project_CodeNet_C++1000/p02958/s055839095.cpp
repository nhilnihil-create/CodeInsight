#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	int p[55];
  	rep(i,n)cin>>p[i];
  
  	int cnt=0;//次に格納されている数が+1になってない回数
  
  for(int i=0;i<n;i++){
  	if(p[i]-i!=1){
    	cnt++;
    }
  }
  
  if(cnt==2||cnt==0){
  	cout<<"YES"<<endl;
  }
  
  else{
  	cout<<"NO"<<endl;
  }
    

}