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
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vi ids(N);
    for(int i=0; i<N; i++) ids[i]=i;
    sort(all(ids), [&](int i, int j){return A[i] < A[j];});
    for(int i=0; i<N; i++){
        cout << ids[i]+1;
        if(i != N-1) cout << " ";
    }
    cout << endl;
    return 0;   
}