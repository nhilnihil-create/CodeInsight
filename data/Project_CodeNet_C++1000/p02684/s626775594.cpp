#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const long long INF = 1LL<<60;

typedef pair<ll,ll> Pair;
int main(){

ll N,K;

cin >> N >> K;

vector<Pair> A(N+1);

A[1].second = 1;

for(ll i = 1;i <= N;++i){
    cin >> A[i].first;
    A[i].second = 0;
}

ll index = A[1].first;
ll telcnt = 0;
ll ans;
  
while(A[index].second != 2 && K > telcnt){
    ans = index;
    ++A[index].second;
    index = A[index].first;
    ++telcnt;
}

if(K == telcnt) cout << ans << endl;
else{

ll count = 0;
K = K - telcnt;

for(ll i = 1;i <= N;++i) if(A[i].second == 2) ++count;
  
K = K%count;
telcnt = 0;
  
while(K > telcnt){
    ans = index;
    ++A[index].second;
    index = A[index].first;
    ++telcnt;
}

cout << ans << endl;
  
}
  
return 0;

}
