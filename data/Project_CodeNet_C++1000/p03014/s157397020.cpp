#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

void solve(){
	int h,w; cin >> h >> w;
	int l[h+2][w+2],r[h+2][w+2],u[h+2][w+2],d[h+2][w+2];
	
	// set everything to 0 
	FOR(i,0,h+2){
		FOR(j,0,w+2){
			l[i][j] = 0;
			r[i][j] = 0;
			u[i][j] = 0;
			d[i][j] = 0;
		}
	}
	
	
	
	FOR(i,1,h+1){
		FOR(j,1,w+1){
			char c; cin >> c;
			if(c == '#'){
				l[i][j] = -1;
		        r[i][j] = -1;
                u[i][j] = -1;
                d[i][j] = -1;
            }
		}
	}
	
	//debuga2(l,h+2,w+2);
	//debuga2(l,h+2,w+2);
	//debuga2(l,h+2,w+2);

    // now dp each of the grids e.g. l[i][j] indicates number of free cells to thr left of the cur cell
    FOR(i,1,h+1){
        FOR(j,2,w+1){
            if(!l[i][j]) l[i][j] += l[i][j-1]+1;
        }
    }

    FOR(i,1,h+1){
        for(int j = w-1; j>=1; --j){
            if(!r[i][j]) r[i][j] += r[i][j+1]+1;
        }
    }

	//debuga2(u,h+2,w+2);
    FOR(i,2,h+1){
        FOR(j,1,w+1){
            if(!u[i][j]) u[i][j] += u[i-1][j]+1;
        }
    }
    //debuga2(u,h+2,w+2);

    for(int i = h-1; i>=1; --i){
        FOR(j,1,w+1){
            if(!d[i][j]) d[i][j] += d[i+1][j]+1;
        }
    }
	
    int ans = 0;
    FOR(i,1,h+1){
        FOR(j,1,w+1){
            if(u[i][j]!=-1){
                ans = max(ans,u[i][j] + d[i][j] + l[i][j] + r[i][j] + 1);
            }
        }
    }

    cout << ans;
}

 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 
