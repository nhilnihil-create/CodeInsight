#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

ll X, Y, A, B ,C;
ll P[110000];
ll Q[110000];
ll R[110000];


int main(void){

    cin >> X >> Y >> A >> B >> C;
    for (int i = 0; i < A;i++) cin >> P[i];
    for (int i = 0; i < B;i++) cin >> Q[i];
    for (int i = 0; i < C;i++) cin >> R[i];

    sort(P,P+A,greater<int>());
    sort(Q,Q+B,greater<int>());
    sort(R,R+C,greater<int>());

    ll ans = 0;
    ll S[X + Y];

    for (int i = 0; i < X;i++) {
        ans += P[i];
        S[i] = P[i];
    }
    for (int i = 0; i < Y;i++) {
        ans += Q[i];
        S[X + i] = Q[i];
    }
    sort(S,S+X+Y);

    ll limit = X + Y;
    if  (X + Y > C) limit = C;
    for (int i = 0; i < limit;i++){
        if (S[i] < R[i]) ans += R[i] - S[i];
        else break;
    }


    cout << ans << endl;
    
    return 0;
}