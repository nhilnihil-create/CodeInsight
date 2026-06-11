#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int N,K;
	cin >> N >> K;

	vector<P> G;
	rep(i,N-1){ G.push_back(make_pair(1,i+2)); }
	int E = (N-1)*(N-2) / 2;
	if(E<K){ cout <<-1<<endl; return 0;}
	bool f=false;
	for(int i=2; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			if(E==K){f=true; break;}
			G.push_back(P(i,j));
			E--;
			if(E<0){f=true; break;}
		}
		if(f)break;
	}

	if(E<0)cout << -1 << endl;
	else {
		cout << G.size() << endl;
		for(P p: G){
			cout << p.first << " " << p.second << endl;
		}
	}
}


