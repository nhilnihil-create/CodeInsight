#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 1e5+10;
const lint LNF = 2e18;

int n;
lint A[MAX], sum, ans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i], sum^=A[i];
	for(int i=1; i<=n; i++){
		for(lint e = 1LL<<59; e>0; e>>=1)
			if((A[i]&e) && (sum&e)) A[i]^=e;
	}

	for(lint e = 1LL<<59, x=0; e>0; e>>=1, x=0){
		for(int i=1; i<=n; i++) if(A[i]&e) x=A[i];
		if(~A[0]&e) A[0]^=x;
		for(int i=1; i<=n; i++) if(A[i]&e) A[i]^=x;
	}
	cout<<A[0]*2 + sum<<'\n';


	return 0;
}
