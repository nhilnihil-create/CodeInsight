#include <bits/stdc++.h>
using namespace std;

int main(){
 	int a,n,num=0;
  	cin >> n;
  	for(a=1;a<n;a++){
    	num += (n-1)/a;
    }
  	cout << num << endl;
}
