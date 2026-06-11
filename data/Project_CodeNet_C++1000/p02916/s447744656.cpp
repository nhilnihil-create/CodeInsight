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
    vi A(N), B(N), C(N-1);
    ll sum=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i]--;
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    for(int i=0; i<N-1; i++){
        cin >> C[i];
    }
    for(int i=0; i<N; i++){
        sum+=B[A[i]];
        if(i != 0 && A[i]-A[i-1] == 1){
            sum+=C[A[i-1]];
        }
    }
    cout << sum << endl;
    return 0;
}