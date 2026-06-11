#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
 
using namespace std;
 
typedef unsigned long long ll;
typedef pair<ll, ll> pair_;
 
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
 
int main(){

  vector<int> a_ = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int K;
    cin >> K;
    cout << a_[K-1];

   
    return 0;
 
}