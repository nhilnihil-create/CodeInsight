#include <bits/stdc++.h>
using namespace std;
 
int main() {
  	int a,v,b,w,t;
  	cin >> a >> v >> b >> w >> t;
  	int sa,sb;
  	sa = abs(a - b);
  	if(v<=w){
      cout << "NO" << endl;
      return 0;
    }
  	sb = v-w;
 
  	if(sa <= (long long)sb * t){
     	cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
 
  	return 0;
}