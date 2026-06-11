#include <atcoder/all>
#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    for (int i = 0; i < Q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a) cout << fw.sum(b, c) << endl;
        else fw.add(b, c);
    }
}