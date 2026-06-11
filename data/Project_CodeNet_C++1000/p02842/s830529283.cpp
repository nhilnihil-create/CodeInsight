#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,x=0;
  	cin >> n;
  	for(int i=1;i<=n;i++){
    	int a = i*1.08;
      	if(a==n) {x=i; break;}
    }
  	if(x==0) cout << ":(" << endl; 
  	else cout << x << endl;
}