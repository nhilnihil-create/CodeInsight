#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

map<long long, long long> prime_list(long long n){
  map<long long, long long> ans;
  for(long long i=2;i*i<=n;++i){
    while(n%i==0){
      ++ans[i];
      n=n/i;
    }
  }
  if(n!=1){
    ++ans[n];
  }
  return ans;
}

long long X;

int main(){
	cin >> X;
	while(1) {
		map<long long, long long> memo = prime_list(X);
		if(memo.size() == 1 && memo.count(X) == 1){
			cout << X << endl;
			return 0;
		}
		X++;
	}

}