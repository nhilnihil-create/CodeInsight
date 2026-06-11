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
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i=0; i<N; i++){
        cin >> A[i];
        pq.push(A[i]);
    }
    ll res=0;
    for(int i=0; i<M; i++){
        int tmp=pq.top();
        pq.pop();
        pq.push(tmp/2);
    }
    while(!pq.empty()){
        res+=pq.top();
        pq.pop();
    }
    cout << res << endl;
    return 0;
}