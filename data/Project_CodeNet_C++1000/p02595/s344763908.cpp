#include "bits/stdc++.h"
using namespace std;

int main(){
	long long a,b,d;
  	int t;
  	cin>>t;cin>>d;
  int ans=0;
  	for(int i=0;i<t;i++){
    cin>>a;cin>>b;
      if((a*a+b*b)<=(d*d)){ans++;}
    }

cout<<ans;
}