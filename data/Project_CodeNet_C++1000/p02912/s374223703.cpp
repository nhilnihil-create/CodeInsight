#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    multiset<int> ms;
    for(int i=0; i<N; i++){
        cin >> A[i];
        ms.insert(A[i]);
    }
    ll res=0;
    for(int i=0; i<M; i++){
        int num=*(ms.rbegin());
        ms.erase(ms.find(num));
        ms.insert(num/2);
    }
    for(auto x : ms){
        res+=x;
    }
    cout << res << endl;
    return 0;
}