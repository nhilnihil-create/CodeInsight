#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

  
int main() {
   
    int N;
    cin >> N;
   
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
   
    sort(A.begin(), A.end(), greater<ll>());
   
    ll ans = A[0];
   
    queue<ll> Q;
    for (int i = 0; i < 2; i++) Q.push(A[1]);
   
    for (int i = 2; i < N; i++) {
        ans += Q.front();
        Q.pop();
        for (int j = 0; j < 2; j++) {
            Q.push(A[i]);
        }
    }
    cout << ans << endl;
   return 0;
}