#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;

ll n, money, t, stock;

int main(){
	cin>>n;
    money= 1000;
	stock = 0;
	vector<ll> vec(n, 0);
	for(int i = 0; i < n; ++i)cin>>vec[i];
	for(int i = 0; i < n; ++i){
		money += vec[i] * stock;
		stock = 0;
		if(i < n - 1 && vec[i] < vec[i + 1]){
			stock += money / vec[i];
			money %= vec[i];
		}
	}
	cout<<money<<endl;
	return 0;
}

