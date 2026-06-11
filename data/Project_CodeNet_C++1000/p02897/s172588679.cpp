#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
typedef long long ll;

int main() {
	double n;
   cin>>n;
  int kisuu;
  rep(i,n){
  	if(i%2==1){
    	kisuu++;
    }
    
    
  }
  double kotae=kisuu/n;
  cout<<kotae<<endl;
}