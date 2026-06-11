#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	string s;
  	cin>>s;
  
  	int hug=0;
  	int ketu=s.size();


  
  rep(i,ketu){
  	if(s[i]!=s[ketu-i-1])
    	hug++;
    }

  
  cout<<hug/2<<endl;
  
  
}