#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<long long>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;

int main() {
    int N; cin >> N; 
    if(N % 1000 == 0) cout << 0;
    else cout << 1000 - (N % 1000);

}