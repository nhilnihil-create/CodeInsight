#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define CLR(a) memset(a,0,sizeof(a))

typedef long long int ll;

using namespace std;

int main(){
    int V,E;
    cin >> V >> E;
    vector<int> s(E);
    vector<int> t(E);
    vector<int> res;
    vector< vector<int> > v(V);
    vector< vector<int> > rv(V);
    vector<bool> used(V,false);
    int count = 0;

    REP(i,E) scanf("%d%d",&s[i],&t[i]);
    REP(i,E) v[s[i]].PB(t[i]);
    REP(i,E) rv[t[i]].PB(s[i]);
    REP(i,V){
	REP(j,V){
	    if(used[j]) continue;
	    if(rv[j].size() == 0){
		res.PB(j);
		used[j] = true;
		int size = v[j].size();
		REP(k,size) rv[v[j][k]].erase(rv[v[j][k]].begin());
		fill(ALL(v[j]),0);
		break;
	    }
	}
    }

    REP(i,V) cout << res[i] << endl;

    return 0;
}