#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	string tmp;
	rep(i,N) cin >> tmp[i];
	ll p = stoi(tmp);
	rep(i,N) cin >> tmp[i];
	ll q = stoi(tmp);
	
	int v[N];
	int totN = 1;
	rep(i,N) {
		v[i] = i+1;
		totN *= i+1;
	}

	int k=0;
	ll ps[totN];
	do {
		string s="";
		for (int x : v) s += to_string(x);
		ps[k] = stoi(s);
		k++;
	}while (next_permutation(v,v+N));

	int a, b;
	rep(i,totN) {
		if (ps[i] == p) a = i;
		if (ps[i] == q) b = i;
	}	

	cout << abs(a-b) << endl;

	return 0;
}
