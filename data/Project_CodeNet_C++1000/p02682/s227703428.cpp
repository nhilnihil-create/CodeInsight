#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int na = min(k,a);
	k-=na;
	int nb = min(b, k);
	k-=nb;
	int nc = min(c, k);
	k-=nc;
	cout<<na-nc;
  return 0;
}