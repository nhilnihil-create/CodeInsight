#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n,k;
  	cin>>n>>k;
  
  	int h[n];
  	rep(i,n){
    	cin>>h[i];
    }
  
  int noreru=0;
  
  rep(j,n){
  	if(h[j]>=k){
    	noreru++;
    }
  }
  
  cout<<noreru<<endl;
}