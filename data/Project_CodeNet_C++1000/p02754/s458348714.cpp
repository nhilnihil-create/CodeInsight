#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,b,r,count=0,res;
  	cin >> n >> b >> r;
  	count = n/(b+r);
  	
  	res = b*count;
  	n %= (b+r);
  	if((n-b)<=0) res += n;
  	else res += b;
   
  	cout << res << endl;
}