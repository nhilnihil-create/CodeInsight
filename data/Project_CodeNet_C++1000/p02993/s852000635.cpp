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

	string s;
	cin>>s;
	
	for(int i=0; i<s.length()-1; i++){
		if(s[i] == s[i+1]){
			writeln("Bad");
			return 0;
		}
	}
	writeln("Good");
}


