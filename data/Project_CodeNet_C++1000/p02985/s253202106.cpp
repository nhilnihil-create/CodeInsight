    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
    using T = ll;
     
const int MOD = 1e9 + 7;
const ll ZER = 0;

bool seen[100100];
int main(){
    ll n, k;
    cin >> n >> k;
    Graph G(n);
    rep(i, n - 1){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<P> q;
    q.push(P(0, 1));
    ll res = k;
    while(!q.empty()){
        P p = q.front();
        q.pop();
        int v = p.first;
        seen[v] = true;
        ll cnt = p.second;
        for(auto nv : G[v]){
            if(seen[nv])continue;
            if(cnt > k){
                cout << 0 << endl;
                return 0;
            }
            res = res * (k - cnt) % MOD;
            cnt++;
            q.push(P(nv, min((ll)2, p.second + 1)));
        }
    }
    cout << res << endl;
}

