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
    int N; cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    ll M, cur;
    vector<pii> res;
    sort(all(A));
    if(A[0] >= 0){
        cur=A[0];
        for(int i=1; i<N-1; i++){
            res.push_back({cur, A[i]});
            cur=cur-A[i];
        }
        res.push_back({A[N-1], cur});
        M=A[N-1]-cur;
    }
    else if(A[N-1] < 0){
        cur=A[N-1];
        for(int i=0; i<N-1; i++){
            res.push_back({cur, A[i]});
            cur=cur-A[i];
        }
        M=cur;
    }
    else{
        cur=A[0];
        int id=N-1;
        while(A[id-1] > 0){
            res.push_back({cur, A[id]});
            cur=cur-A[id];
            id--;
        }
        int id2=1;
        res.push_back({A[id], cur});
        cur=A[id]-cur;
        while(id2 != id){
            res.push_back({cur, A[id2]});
            cur=cur-A[id2];
            id2++;
        }
        M=cur;
    }
    
    cout << M << endl;
    for(int i=0; i<N-1; i++){
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}