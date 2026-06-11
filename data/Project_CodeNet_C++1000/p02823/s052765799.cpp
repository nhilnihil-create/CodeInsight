#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll N,A,B;
    cin >> N >> A >> B;
    if(A%2==B%2){
        cout << (B-A)/2 << endl;
    } else {
        ll to = min(A-1,N-B) + 1;
        ll diff = (B-A-1)/2;
        cout <<  to+diff << endl;
    }
}