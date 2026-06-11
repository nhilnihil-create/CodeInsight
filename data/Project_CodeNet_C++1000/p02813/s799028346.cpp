#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<Int, Int> P;

int main(){
    int N; cin >> N;
    vector<int> P(10), Q(10);
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> Q[i];

    vector<int> perm(10);
    rep(i,N) perm[i] = i+1;

    int a, b, cnt = 0;
    do {
        bool flag1 = true, flag2 = true;
        rep(i,N){
            if (P[i] != perm[i]) flag1 = false;
            if (Q[i] != perm[i]) flag2 = false;
        }

        if(flag1) a = cnt;
        if(flag2) b = cnt;

        cnt++;
    } while (next_permutation(perm.begin(),perm.begin()+N));

    cout << abs(a-b) << endl;
    
}
