#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    vector<ll> A;
    for(int i=0; i<N; i++) {
        ll x; cin >> x;
        A.push_back(x);
    }
    sort(A.begin(),A.end());
    for(int i=0; i<N-1; i++) {
        if(A[i]==A[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}