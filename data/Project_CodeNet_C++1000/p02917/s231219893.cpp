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
    vi B(N-1);
    for(int i=0; i<N-1; i++){
        cin >> B[i];
    }
    ll res=B[0]+B[N-2];
    for(int i=0; i<N-2; i++){
        if(B[i] < B[i+1]){
            res+=B[i];
        }
        else{
            res+=B[i+1];
        }
    }
    cout << res << endl;
    return 0;
}