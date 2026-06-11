#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 1e6 + 10;

vector<int> D(MAX,INF);

void sieve(){

	D[1] = 1;

	for(int i = 2; i < MAX; i++){
		if(D[i] != INF) continue;
		D[i] = i;
		for(int j = 2; j * i < MAX; j++) D[j*i] = min(D[i*j], i);
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	int N;
	cin >> N;

	vector<int> V(N);

	unordered_set<int> GG;

	vector<unordered_set<int>> DIV(N);

	bool pc = 1;
	int sc;

	int i = 0;
	for(auto &x : V) {
		cin >> x;

		if(!i) sc = x;
		else sc = __gcd(sc,x);

		while(x != 1){
			DIV[i].insert(D[x]);
			x /= D[x];
		}

		for(auto y : DIV[i]){
			if(GG.count(y)) pc = 0;
			GG.insert(y);
		}		

		i++;
	}

	if(pc){
		cout << "pairwise coprime\n";
		return 0;
	}

	cout << (sc != 1? "not coprime" : "setwise coprime") << endl;
	return 0;
}
