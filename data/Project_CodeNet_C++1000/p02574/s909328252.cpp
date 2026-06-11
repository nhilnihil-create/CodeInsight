#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+7;
int t,n,m;
vector<int> sieve,cnt,primes;

void precal(){
	sieve = cnt = vector<int>(maxn,0);
	for (int i=2; i<maxn; i++){
		if (sieve[i] == 0){
			primes.push_back(i);
			for (int j=i; j<maxn; j+= i){
				sieve[j] = i;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	precal();
	int x,maxf;
	for (int i=0; i<n; i++){
		cin >> x;
		while (x > 1){
			maxf = sieve[x];
			++cnt[maxf];
			while (x % maxf == 0) x/=maxf;
		}
	}
	
	int state = 0;
	for (int i=0, s=primes.size(); i<s; i++){
		int now = primes[i];
		if (cnt[now] >= n) state = 2;
		else if (cnt[now] >= 2){
			state = 1;
		}
		
		if (state == 2) break;
	}
	
	if (state == 0) cout << "pairwise coprime" << endl;
	else if (state == 1) cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl; 
	return 0;
}
