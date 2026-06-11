#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    int A[3][3] = {0};
    bool bing[3][3] = {false};
    bool ans = false;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> A[i][j];
        }
    }
    int N; cin >> N;
    int b[N+10] = {0};
    for(int i=0; i<N; i++) cin >> b[i];

    for(int k=0; k<N; k++) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(b[k] == A[i][j]) bing[i][j] = true;
           }
        }
    }

    if(bing[0][0] && bing[1][0] && bing[2][0]) ans = true;
    else if(bing[0][1] && bing[1][1] && bing[2][1]) ans = true;
    else if(bing[0][2] && bing[1][2] && bing[2][2]) ans = true;

    if(bing[0][0] && bing[0][1] && bing[0][2]) ans = true;
    else if(bing[1][0] && bing[1][1] && bing[1][2]) ans = true;
    else if(bing[2][0] && bing[2][1] && bing[2][2]) ans = true;

    if(bing[0][0] && bing[1][1] && bing[2][2]) ans = true;
    else if(bing[0][2] && bing[1][1] && bing[2][0]) ans = true;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}