#include<bits/stdc++.h>
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

int main(){
	long long N;
	cin >> N;
	map<long long, long long> memo = prime_list(N);


	long long ans = 0;

	for(auto item: memo) {
		long long num = 0;
		long long idx = 1;
		while(num + idx <= item.second) {
			num += idx;
			idx++;
		}
		ans += idx - 1;
	}
	cout << ans << endl;
}