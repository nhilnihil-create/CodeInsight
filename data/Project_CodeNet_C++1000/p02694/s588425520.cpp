#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

ll mod = 1000000007;


int main() {
	long long x; cin >> x;
	int cnt = 0;
	long long money = 100;
	while(money < x){
		long long tmp = money /100;
		money += tmp;
		cnt++;
	}
	cout << cnt << endl;
}
