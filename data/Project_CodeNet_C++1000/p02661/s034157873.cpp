#include<bits/stdc++.h>
using namespace std;

long long N;

vector<pair<long long, long long> > ab;
vector<pair<long long, long long> > ba;


int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		long long a, b;
		cin >> a >> b;
		ab.push_back(make_pair(a, b));
		ba.push_back(make_pair(b, a));
	}

	if(N % 2 == 1) {
		sort(ab.begin(), ab.end());
		sort(ba.begin(), ba.end(), greater<pair<long long, long long> >());
		cout << ba[N/2].first - ab[N/2].first + 1 << endl;
	} else {
		sort(ab.begin(), ab.end());
		sort(ba.begin(), ba.end(), greater<pair<long long, long long> >());
		cout << (ba[N/2-1].first + ba[N/2].first) - (ab[N/2-1].first + ab[N/2].first) + 1 << endl;
	}
}
