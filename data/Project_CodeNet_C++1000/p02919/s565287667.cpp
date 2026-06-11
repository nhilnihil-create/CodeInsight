#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

ll le[100001];
ll lex[100001];
ll ri[100001];
ll rix[100001];

int main(){
	ll n;
	cin >> n;
	vector<ll> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i <= 100000; i++){
		le[i] = -1;
		lex[i] = -1;
		ri[i] = -1;
		rix[i] = -1;
	}

	priority_queue<pai, vector<pai>, greater<pai> > pq1, pq2;
	priority_queue<pai, vector<pai>, greater<pai> > pq3, pq4;

	for (int i = 0; i < n; i++){
		pq1.push(make_pair(p[i], i));
		int temp = p[i];
		while (!pq3.empty() && pq3.top().first < temp){
			auto p = pq3.top();
			pq3.pop();
			rix[p.second] = i-1;
 		}
		while (pq1.top().first < temp){
			auto p = pq1.top();
			pq1.pop();
			ri[p.second] = i;
			pq3.push(p);
		}
	}
	while(!pq3.empty()){
		auto p = pq3.top();
		pq3.pop();
		rix[p.second] = n-1;
	}
	for (int i = n-1; i >= 0; i--){
		pq2.push(make_pair(p[i], i));
		int temp = p[i];
		while (!pq4.empty() && pq4.top().first < temp){
			auto p = pq4.top();
			pq4.pop();
			lex[p.second] = i+1;
		}
		while (pq2.top().first < temp){
			auto p = pq2.top();
			pq2.pop();
			le[p.second] = i;
			pq4.push(p);
		}
	}
	while(!pq4.empty()){
		auto p = pq4.top();
		pq4.pop();
		lex[p.second] = 0;
	}

	ll ans = 0;

	for (ll i = 0; i < n; i++){
		if (ri[i] != -1 && le[i] != -1){
			ans += p[i]*(rix[i]-ri[i]+1)*(i-le[i]);
			ans += p[i]*(le[i]-lex[i]+1)*(ri[i]-i);
		}else if (ri[i] != -1){
			ans += p[i]*(rix[i]-ri[i]+1)*(i+1);
		}else if (le[i] != -1){
			ans += p[i]*(le[i]-lex[i]+1)*(n-i);
		}
	}
	cout << ans << endl;
	return 0;
}
