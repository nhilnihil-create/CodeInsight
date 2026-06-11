#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main() { 
    ll K;
    string S;
    cin >> K >> S;
    if (S.size() <= K) cout << S << endl;
    else{
      for (int i = 0; i < K; i++) cout << S[i];
      cout << "..." << endl;
    }
    return 0;
}