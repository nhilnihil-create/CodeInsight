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

	int n,k;cin>>n>>k;
	string s; cin>>s;

	int score =0;
	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1])score++;
	}
	int ans = min(score+2*k,n-1);

	writeln(ans);

}


