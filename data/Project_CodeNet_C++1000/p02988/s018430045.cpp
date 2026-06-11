#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  int p[n];
  rep(i,n)cin>>p[i];
  
  int mitasu=0;
  
 for(int j=1;j<n-1;j++){
  	if(p[j]>p[j-1]&&p[j]<p[j+1]){
    	mitasu++;
    }
   
   else if(p[j]<p[j-1]&&p[j]>p[j+1]){
   		mitasu++;
   }
 }
  
  cout<<mitasu<<endl;
}