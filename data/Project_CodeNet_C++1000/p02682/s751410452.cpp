#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,k;
  	cin >> a >> b >> c >> k;
  	
  	if(k == a+b+c){
      cout << (a - c);
    }else if(k > a+b && k < a+b+c){
      cout << a-(k - (a+b));
    }else if(k > a && k <= a+b){
      cout << a;
    }else{
      cout << k;
    }
  return 0;
}