#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

vector<int> G[MAX_N];
vector<int> deg;

void tsort(int n, vector<int>& res) {
	queue<int> que;
	rep(i,n){
        if(deg[i] == 0){
            que.push(i);
        }
    }
	while(!que.empty()){
		int p = que.front();
        que.pop();
		res.pb(p);
		rep(i,G[p].size()){
            if(--deg[G[p][i]] == 0){
                que.push(G[p][i]);
            }
        }
	}
	if(*max_element(all(deg)) != 0){
        res.clear();
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    deg.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        deg[b]++;
    }
    vector<int> res;
    tsort(n,res);
    if((int)res.size() != 0){
        rep(i,res.size()){
            cout << res[i] << endl;
        }
    }else{
        cout << "-1\n";
    }
    return 0;
}