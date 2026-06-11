#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

int main(){
	int K;
	cin >> K;
	long long int ans = 0;
	rep(i,K){
		rep(j,K){
			rep(k,K){
				ans += gcd(i+1,gcd(j+1,k+1));
			}
		}
	}
	cout << ans << endl;
}
