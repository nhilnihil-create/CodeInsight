#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void vprint(vector<ll> A){
    ll L = A.size();
    FOR(i, 0, L){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
}

VI topological_sort(VV& G){
    ll N = G.size();
    
    // 入次数
    VI IN(N, 0);
    REP(i, N){
        for(ll to : G[i]){
            IN[to]++;
        }
    }

    stack<ll> st; // 入次数0のものを入れる
    REP(i, N){
        if(IN[i]==0) st.push(i);
    }

    VI ret;
    while(!st.empty()){
        ll i = st.top();
        st.pop();
        ret.push_back(i);
        for(ll to : G[i]){
            IN[to]--;
            if(IN[to]==0){
                st.push(to);
            }
        }
    }

    // 成功したか確認
    for(ll in : IN){
        if(in!=0){
            // 失敗（DAGじゃなかった）
            VI empty_vector;
            return empty_vector;
        }
    }
    // 正常の戻り値
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll V, E;
    cin >> V >> E;

    VV G;
    G.resize(V);

    REP(i, E){
        ll s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    auto A = topological_sort(G);
    for(ll a : A){
        p(a);
    }
    
    return 0;
}
