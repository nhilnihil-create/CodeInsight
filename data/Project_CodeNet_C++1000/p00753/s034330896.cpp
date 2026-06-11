#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-14

#define all(v) v.begin(),v.end()
// #define INF
// #define mp
// #define pb

// #define fi
// #define se

// #define each

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

typedef long long ll;

int main(){
	while(1){
		int n; cin>>n;
		if(n==0) break;

		vector<bool> P(n*2+1,true);
		P[0] = P[1] = false;
		for(int i=2;i*i<=2*n;i++) if(P[i]){
			for(int j=2;j*i<=2*n;j++) P[i*j] = false;
		}

		int ans = 0;
		REP(i,n+1,2*n+1) if(P[i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}