#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int p,q,r;
  	cin>>p>>q>>r;
  
  int teki=max(p,max(q,r));
  
  	cout<<p+q+r-teki<<endl;
}