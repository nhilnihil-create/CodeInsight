#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;
const int N=2e5+5;


int main(){
    int N; cin >> N;
    string S, T; cin >> S >> T;
    for(int i=0; i<N; i++){
        cout << S[i] << T[i];
    }
    cout << endl;
    return 0;
}