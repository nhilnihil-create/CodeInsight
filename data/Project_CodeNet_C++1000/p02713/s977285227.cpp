#include<bits/stdc++.h>
using namespace std;

long long K;

long gcd(long a,long b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}

int main(){
	cin >> K;
	long long ans = 0;
	for(long long a = 1; a <= K; a++) {
		for(long long b = 1; b <= K; b++) {
			for(long long c = 1; c <= K; c++) {
				ans += gcd(a, gcd(b, c));
			}
		}
	}
	cout << ans << endl;

}