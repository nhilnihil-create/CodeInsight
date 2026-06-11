#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, D, A;

struct xd {
	ll x;
	ll undamage;
};

int main(){
	cin >> N >> D >> A;
	vector<pii> v(N);
	
	// first = x, second = h
	for ( int i = 0; i < N; i++ ){
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v.begin(),v.end());
	
	// 左から順に処理する
	ll damage = 0; // 現在位置のダメージ
	queue<xd> q; // ダメージの効果が切れる位置
	ll count = 0;
	
	for ( int l = 0; l < N; l++ ){
		ll x = v[l].first;
		ll h = v[l].second;
		
		while ( !q.empty() && q.front().x < x ){
			damage -= q.front().undamage;
			q.pop();
		}
		
		if ( h-damage > 0 ){
			ll n = (h-damage+A-1)/A;
			damage += n*A;
			q.push({x+D*2, n*A});
			count += n;
		}
	}
	
	cout << count << endl;
	
	return 0;
}

