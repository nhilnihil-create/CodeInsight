#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;


int main() {
    char alpha; cin >> alpha;
    int kind = alpha;
    int A = 'A', Z='Z';
    if(A <= kind && kind <= Z){
        cout << 'A' << endl;
    } else {
        cout << 'a' << endl;
    }
}