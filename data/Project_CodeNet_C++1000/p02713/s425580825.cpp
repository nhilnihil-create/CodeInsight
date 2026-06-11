#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(long long i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,sum = 0;
  cin >> N;
  froop1(1,N + 1){
	for(int j = 1;j <= N;j++){
		for(int k = 1;k <= N;k++){
          sum += gcd(i,gcd(j,k));
		}
	}
  }
  cout << sum << endl;

}