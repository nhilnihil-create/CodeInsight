#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;
LLi mod;

//vector<LLi>を出力
void PVL(vector<LLi> pvv) {
	rep(i, (int)pvv.size()-1) cout << pvv[i] SP;
	cout<< pvv[(int)pvv.size()-1] <<endl;
}
 
LLi modpow(LLi a, LLi n) {
    LLi res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){

	LLi n, p, ans;
  	string s;
	vector<LLi> v, ten(1), bak;
	cin>> n >> p >> s;
  
  	v.resize(n);
  	bak.resize(p);
  
  	rep(i, n) v[i]=(LLi)(s[i]-'0');
  
  	if(p==2){
      	ans=0;
      	rep(i, n) if(v[i]%2==0) ans+=i+1;
      	cout<< ans <<endl;
      	return 0;
    }
  
  	if(p==5){
      	ans=0;
      	rep(i, n) if(v[i]%5==0) ans+=i+1;
      	cout<< ans <<endl;
      	return 0;
    }
  
  	reverse(all(v));
      
    ten[0]=1;
  	rep(i, n-1) ten.push_back((ten[i]*10)%p);
  
  	rep(i, n) v[i]=(v[i]*ten[i])%p;
  	rep(i, n-1) v[i+1]=(v[i+1]+v[i])%p;
  
  	rep(i, n) bak[v[i]]++;
  	ans=bak[0]*(bak[0]+1)/2;
  	for(int i=1;i<p;i++) ans+=bak[i]*(bak[i]-1)/2;
  
  	//PVL(v);
  	//PVL(bak);
  	cout<< ans <<endl;

	return 0;
}