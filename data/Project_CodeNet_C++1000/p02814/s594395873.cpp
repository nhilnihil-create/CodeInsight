#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

int imax=2147483647;
long long int llimax=9223372036854775807;

//int型vectorを出力
void PV(vector<int> pvv) {
	rep(i, pvv.size()) cout << pvv[i] SP;
	cout << endl;
}

//LLi型vectorを出力
void PVL(vector<LLi> pvv) {
	rep(i, pvv.size()) cout << pvv[i] SP;
	cout << endl;
}

LLi gcd(LLi a, LLi b) {
	if(a<0) a=b;
	if(b<0) b=a;
    if (b == 0) return a;
    return gcd(b, a%b);
}

LLi lcm(LLi a, LLi b) {
    return a/gcd(a, b)*b;
}

int main(){

	LLi n, m, tw=1;
	vector<LLi> v;

	cin>> n >> m;
	v.resize(n);

	rep(i, n){
      cin >> v[i];
      v[i]/=2;
    }

  	while(1){
      if((v[0]/tw)%2==0) tw*=2;
      else break;
    }
  
	rep(i, n) {
		if ((v[i]/tw)%2!=1 || (v[i]*2/tw)%2!=0){
          cout<< "0" <<endl;
          return 0;
        }
	}
  //PV(v);
  
  	for(int i=0;i<n-1;i++){
      v[i+1]=lcm(v[i], v[i+1]);
    }
  //cout<< v[n-1] <<endl;

	cout<< m/v[n-1]-m/v[n-1]/2 << endl;
 
	return 0;
}