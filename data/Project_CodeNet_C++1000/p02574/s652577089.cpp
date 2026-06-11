#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+1;
vector<bool> primes(N,true);
void soe()
{
	for(int i = 2; i * i <= N;++i){
		if(primes[i] == true){
			for(int j = i*i; j < N;j+=i)
				primes[j] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	soe();
	int n;
	cin >> n;
	int gc;
	vector<int> freq(1e6+1,0);
	for(int i = 1; i <= n;++i){
		int x;
		cin >> x;
		++freq[x];
		if(i == 1)
			gc = x;
		else
			gc = __gcd(gc,x);
	}
	int flag = 1;
	for(int i = 2; i < N;++i){
		if(primes[i]){
			int cnt = 0;
			for(int j = i; j < N;j+=i){
					cnt += freq[j];
					if(cnt > 1){
						flag = 0;
						break;
					}
				}
			}
			if(flag == 0)
				break;
	}
	if(flag == 1)
		cout << "pairwise coprime\n";
	else if(gc == 1)
		cout << "setwise coprime\n";
	else
		cout << "not coprime\n";
}

