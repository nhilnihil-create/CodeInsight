#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    ll N;
    cin >> N;
    ll A[N],A_cum[N+1];
    ll L=0;
    A_cum[0] = 0;
    rep(i,0,N) {
        cin >> A[i];
        L+=A[i];
        A_cum[i+1] = A_cum[i]+A[i]; 
    }
    ll tmp1,tmp2;
    rep(i,0,N) {
        if (A_cum[i+1]==L/2 && L%2==0) {
            cout << 0 << endl;
            break;
        }
        else {
            if (A_cum[i+1]>L/2) {
                tmp2=A_cum[i+1];
                tmp1=A_cum[i];
                ll ans = min(2*tmp2-L,L-2*tmp1);
                cout << ans << endl;
                break;
            }
        }
    }

}



