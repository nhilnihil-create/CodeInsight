#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    bool ok=false;
    if(S.substr(0, N/2) == S.substr(N/2, N)) ok=true;
    cout << (ok ? "Yes":"No") << endl;
    return 0;
}