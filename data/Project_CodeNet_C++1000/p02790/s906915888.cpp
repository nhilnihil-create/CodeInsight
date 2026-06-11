#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int a,b;
  	cin >> a >> b;
  	int res=0,m = min(a,b),M=max(a,b);
  	for(int i=0;i<M;i++){
    	res += m*pow(10,i);
    }
  	cout << res << endl;
}