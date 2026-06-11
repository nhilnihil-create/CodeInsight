#include<bits/stdc++.h>
using namespace std;
using lint = long int;
using P = pair<lint, lint>;
#define MOD 1000000007

lint X, Y;


/*逆元導出*/
lint inv_mod(lint x, lint y){
  	lint a = x, b = y, u = 1, v = 0;
  	lint d;
  	while(b){
    	d = a / b;
      	a -= b * d; swap(a, b);
      	u -= v * d; swap(u, v);
    }
  
  	u %= y;
  	if(u < 0) u += y;
  	return u;
}



lint Comb(lint n, lint r){
  	if(n < 1) return 0;
  	lint res = 1, div = 1;
  	for(lint i = 0; i < r; i++){ 
      	res *= (n-i); res %= MOD;
      	div *= (i+1); div %= MOD;
    }
  	res = (res * inv_mod(div, MOD)) % MOD;
  	return res;
}



P identif_pos(lint x, lint y){
    lint a = (2*x-y)/3, b = (2*y-x)/3;  //a, bは各々の方法の使用回数
    if(a < 0 || b < 0 
       || 3*a != 2*x-y 
       || 3*b != 2*y-x) return {-1, -1};
    else return {a, b};
}


int main(){
    cin >> X >> Y;
  	P p = identif_pos(X, Y);
  	//cout << "a: " << p.first << " b: " << p.second << endl;
    cout << Comb(p.first+p.second, p.first) << endl;
    return 0;
}

