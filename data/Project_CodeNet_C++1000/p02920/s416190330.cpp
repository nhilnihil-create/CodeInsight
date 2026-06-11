#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD (ll)(1e9+7)

int N, M;
ll S[1<<18];
multiset<ll> st1, st2;
int main(){
	cin >> N;
	M = (1<<N);
	for(int i=0; i<M; i++){
		cin >> S[i];
		st1.insert(-S[i]);
	}

	auto itr = st1.begin();
	st2.insert(*itr);
	st1.erase(itr);

	//cout << st1.size() << endl;
	for(int i=0; i<N; i++){
		vector<int> tmp;
		for(auto j=st2.begin(); j!=st2.end(); j++){
			auto itr = st1.upper_bound(*j);
			if(itr == st1.end()){
				cout << "No" << endl;
				return 0;
			}
			tmp.pb(*itr);
			st1.erase(itr);
			//cout << st1.size() << endl;
		}
		for(int j=0; j<tmp.size(); j++){
			st2.insert(tmp[j]);
		}
	}
	cout << "Yes" << endl;
}