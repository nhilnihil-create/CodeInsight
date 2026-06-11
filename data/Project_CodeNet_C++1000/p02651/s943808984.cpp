#include <bits/stdc++.h>
using namespace std;
#define     LL              long long int
#define     FOR(I,A,B)      for( int I = A; I < B; ++I )
#define     SFI(X)          scanf("%d",&X)
#define     SFL(X)          scanf("%lld",&X)
#define     CIN()           ios_base::sync_with_stdio(false), cin.tie(NULL)


int main() {

    int T;

    cin >> T;

    while(T--) {

        int N;

        SFI(N);

        vector<LL>V(N);

        for(auto &I:V) cin >> I;

        string S;

        cin >> S;

        vector<LL>B;

        bool Ans = false;

        for(int I = N - 1; I >= 0; --I) {

            for(auto It:B) if(V[I] > (V[I] ^ It)) V[I] ^= It;

            if(V[I]) {

                if(S[I] == '1') {
                    Ans = true;
                    break;
                } else {
                    B.emplace_back(V[I]);
                }
            }
        }

        cout << Ans << endl;

    }
}
