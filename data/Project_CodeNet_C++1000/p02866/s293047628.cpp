#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, j, k, D[100001], cnt[100001]={0}, max=0;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> D[i];
        cnt[D[i]]++;
        chmax(max, D[i]);
    }

    if(D[1]!=0 || cnt[0]>=2){
        cout << 0 << endl;
    }

    else if(N==1){
        cout << 1 << endl;
    }

    else{
        i = 0;
        while(cnt[i]>=1){
            i++;
        }
        i--;

        if(i==max){
            if(max<=1){
                cout << 1 << endl;
            }
            else{
                ll ans = 1;
                for(j=2; j<=max; j++){
                    //ans *= powl(cnt[j-1],cnt[j]);
                    //ans %= 998244353;
                    for(k=1; k<=cnt[j]; k++){
                        ans *= cnt[j-1];
                        ans %= 998244353;
                    }
                }
                cout << ans << endl;
            }
        }

        else{
            cout << 0 << endl;
        }
    }

    return 0;
}