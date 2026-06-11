#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using pint = pair<ll, ll>;
ll N;
vector<pint> A;

int main(){
    cin >> N;
    A.resize(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i].first;
        A[i].second = i+1;
    }
    sort(A.begin(), A.end());
    for(ll i=0; i<N; i++){
        if(i==N-1){
          cout << A[i].second << endl;
          break;
        }
        cout << A[i].second << " ";
    }

    return 0;
}