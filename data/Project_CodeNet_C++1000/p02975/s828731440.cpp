#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define rvpsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i = 0; i < N; i++) cin >> A[i];
  if (N % 3) {
	for(ll i = 0; i < N; i++) {
    	if (A[i] != 0){
        	cout << "No" << endl; 
          	return 0;
        }          
    }
  	cout << "Yes" << endl;
    return 0;  }
  vector<pair<ll, ll>> triple;
  for(ll i = 0; i < N; i++) {
  	bool exist = false;
    for (ll j = 0; j < triple.size(); j++) {
    	if (A[i] == triple[j].first) {
        	triple[j].second++;
          	exist = true;
        }
    }
    if (exist == false) {
    	triple.emplace_back(A[i], 1);
    }
    if (triple.size() > 3) {
    	cout << "No" << endl; return 0;
    }
  }
  vsort(triple);
  if (triple.size() == 1) {
  	if (triple[0].first == 0) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
    }
  } else if (triple.size() == 2) {
  	if (triple[0].first == 0 && triple[0].second * 2 == triple[1].second) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
    }
  } else {
  	if (triple[0].second == triple[1].second && triple[2].second == triple[1].second
       && (triple[0].first ^ triple[1].first ^ triple[2].first) == 0) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
    }
  }
}