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
    vi L(N);
    for(int i=0; i<N; i++){
        cin >> L[i];
    }
    sort(all(L));
    ll res=0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            int it1=upper_bound(all(L), L[j]-L[i])-L.begin();
            it1=max(it1, j+1);
            int it2=lower_bound(all(L), L[j]+L[i])-L.begin();
            res+=it2-it1;
        }
    }
    cout << res << endl;
    return 0;
}