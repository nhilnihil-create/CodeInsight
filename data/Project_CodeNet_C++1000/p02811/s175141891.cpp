#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=998244353;
const int N=2e5+5;



int main(){
    int K, X; cin >> K >> X;
    bool ans=false;
    if(X <= 500*K) ans=true;
    cout << (ans ? "Yes":"No") << endl;
    return 0;
}