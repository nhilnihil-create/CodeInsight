#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;cin>>n;

	vector<int> p(n);

	for(int i=0; i<n; i++){
		cin>>p[i];
	}

	int cnt=0;
	for(int i=1; i<n-1; i++){
		if(p[i-1] <p[i] && p[i] <p[i+1])cnt++;
		if(p[i-1] >p[i] && p[i] >p[i+1])cnt++;
	}

	writeln(cnt);


}


