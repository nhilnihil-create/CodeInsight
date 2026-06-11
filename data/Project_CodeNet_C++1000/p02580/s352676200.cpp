#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void mod(ll &val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int H,W;
    ll M;
    cin >> H >> W >> M;
    vector<P> h(H);
    vector<P> w(W);
    for(int i = 0;i < H;i++) {
        h.at(i).second = i;
    }
    for(int i = 0;i < W;i++) {
        w.at(i).second = i;
    }
    map<P,int> ma;
    for(int i = 0;i < M;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        h.at(A).first++;
        w.at(B).first++;
        ma[P(A,B)]++;
    }
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    int hmax = h.at(0).first;
    int wmax = w.at(0).first;
    vector<int> hcnt;
    vector<int> wcnt;
    for(int i = 0;i < H;i++) {
        if(h.at(i).first == hmax) {
            hcnt.push_back(h.at(i).second);
        }
    }
    for(int i = 0;i < W;i++) {
        if(w.at(i).first == wmax) {
            wcnt.push_back(w.at(i).second);
        }
    }
    ll hsum = hcnt.size();
    ll wsum = wcnt.size();
    if(hsum * wsum >= M + 1) {
        cout << hmax + wmax << endl;
    }
    else {
        bool ret = false;
        for(int i = 0;i < hsum;i++) {
            for(int j = 0;j < wsum;j++) {
                if(!ma.count(P(hcnt.at(i),wcnt.at(j)))) {
                    ret = true;
                }
            }
        }
        if(ret == true) {
            cout << hmax + wmax << endl;
        }
        else {
            cout << hmax + wmax - 1 << endl;
        }
    }
}