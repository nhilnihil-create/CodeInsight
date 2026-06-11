#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=(ll)1e9+7;

int main(){
    int N; cin >> N;
    vi A(N);
    set<int> s;
    bool ans=1;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(s.count(A[i])) ans=0;
        s.insert(A[i]);
    }
    cout << (ans ? "YES":"NO") << endl;
    return 0;
}