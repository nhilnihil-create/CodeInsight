#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    int L; cin >> L;

    int total = 0;
    rep(i, N){
        total += L+i;
    }
    if(L >= 0){
        total -= L;
    } else if(L+N-1 < 0){
        total -= L+N-1;
    }

    cout << total << endl;

    return 0;
}