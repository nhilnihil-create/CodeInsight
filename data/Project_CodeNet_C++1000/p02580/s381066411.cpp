#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll H, W, M;
    cin >> H >> W >> M;

    vector<int> h(M), w(M);
    rep(i, M) {
        cin >> h[i] >> w[i];
        h[i]--;
        w[i]--;
    }
    
    vector<int> nH(H), nW(W);
   // multiset<tuple<int, int> > xys;
    rep(i, M) {
        nH[h[i]]++;
        nW[w[i]]++;
   //     xys.emplace(make_tuple(w[i], h[i]));
    }

    ll maxNH = *max_element(all(nH));
    ll maxNW = *max_element(all(nW));

    unordered_set<int> xs, ys;
    rep(i, nH.size()) if (nH[i] == maxNH) ys.emplace(i);
    rep(i, nW.size()) if (nW[i] == maxNW) xs.emplace(i);

    // 最大のx, yの交差点に何個対象があるか
    ll cnt = 0;
    rep(i, M) {
        if (ys.find(h[i]) != ys.end() && xs.find(w[i]) != xs.end()) {
            cnt++;
        } 
    }

    bool contains = cnt == xs.size() * ys.size();

    ll res = maxNW + maxNH;
    if (contains) {
        res--;
    }

    put(res);

    // vector<pair<int, int> > pH, pW;
    // rep(i, H+1) {
    //     if (nH[i] > 0) {
    //         pH.push_back({nH[i], i});
    //     }
    // }
    // rep(i, W+1) {
    //     if (nW[i] > 0) {
    //         pW.push_back({nW[i], i});
    //     }
    // }

    // sort(all(pH));
    // reverse(all(pH));
    // sort(all(pW));
    // reverse(all(pW));

    // ll res = 0;
    // rep(i, pH.size()) {
    //     if (pH[i].first < pH[0].first) {
    //         break;
    //     }
    //     rep(j, pW.size()) {
    //         if (pW[j].first < pW[0].first) {
    //             break;
    //         }
    //         ll x = pW[j].second;
    //         ll y = pH[i].second;
    //         bool contains = xys.find(make_tuple(x,y)) != xys.end();
    //         ll v = pW[j].first + pH[i].first;
    //         if (contains) {
    //             v--;
    //         }
    //         res = max(v, res);
    //     }
    // }

    // put(res);
}

signed main(){ Main();return 0;}