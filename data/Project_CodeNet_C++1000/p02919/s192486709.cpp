#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD (LL)(1e9+7)

int N;
ll P[100000];
int place[100001];
multiset<int> st;
ll ans = 0;
int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> P[i];
		place[P[i]] = i;
	}
	st.insert(-1);
	st.insert(-1);
	st.insert(place[N]);
	st.insert(N);
	st.insert(N);
	for(ll i=N-1; i>=1; i--){
		int p = place[i];
		st.insert(p);
		auto itr = st.lower_bound(p);
		itr++;
		int c = *itr;
		itr++;
		int d = *itr;
		itr = st.lower_bound(p);
		itr--;
		int b = *itr;
		itr--;
		int a = *itr;

		ans += (b-a)*(c-p)*i + (p-b)*(d-c)*i;
	}
	cout << ans << endl;
}