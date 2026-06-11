#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define ALL(obj) (obj).begin(),(obj).end();



int main() {
	int n;
  	cin>>n;
  	
  	vector<int> a(n);
  	rep(i,n){cin>>a[i];
  	}
     
  sort(a.begin(),a.end());
  bool ans=true;
  
  for(int i=0;i<n;i++){
  	if(a[i]==a[i+1]){
    	ans=false;
    }
    
  }
	
  
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
  
  
  
}