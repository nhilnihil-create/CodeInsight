#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin >> n;
  
  	char s[n];
  	rep(i,n)cin>>s[i];
  
  	int ans=n;
  
  	for(int i=1;i<n;i++){
    	if(s[i]==s[i-1]){
        	ans--;
        }
    }
  
  cout<<ans<<endl;
}