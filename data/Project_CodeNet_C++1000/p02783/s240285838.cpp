#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

int main(){
    int H, A; cin >> H >> A;
    cout << (H+A-1)/A << endl;
    return 0;
}