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
	
	string s,ss; cin>>s>>ss;
	
	int ct=0;
	for(int i=0; i<3; i++){
		if(s[i] ==ss[i])ct++;
	}
	writeln(ct);

}


