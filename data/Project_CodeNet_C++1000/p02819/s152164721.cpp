#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long X;
	cin>>X;
	if(X==2){
	  cout<<2<<endl;
		return 0;
	}
	while(true){
		long long i=2;
		bool sp=true;
		while (i*i<=X){
			if(X%i==0){
				X++;
				sp=false;
			  break;
			}
			i++;
		}
		if(sp){
			cout<<X<<endl;
		  return 0;
		}
	}
}