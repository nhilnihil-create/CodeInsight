#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    ull B = 1000000007;

    ull now;
    ull plus;
    ull x;
    set<ull> s;
    for (int l = N/2; l >= 1; l--) {
        s.clear();
        now = 0;
        plus = 0;
        x = 1;
        for (int i = 0; i < l; i++) {
            x = x * B;
        }
        for (int i = 0; i < l; i++) {
            plus = plus * B + (S[i] - 'a');
        }
        for (int i = l; i < 2*l; i++) {
            now = now * B + (S[i] - 'a');
        }
        s.insert(plus);
        if(s.count(now)){
            printf("%d\n", l);
            return 0;
        }

        for (int i = 1; i < N - 2*l + 1; i++) {
            plus = plus * B - (S[i-1] - 'a') * x + (S[i+l-1] - 'a');
            now = now * B - (S[i+l-1] - 'a') * x + (S[i+2*l-1] - 'a');
            s.insert(plus);
                if(s.count(now)){
                    printf("%d\n", l);
                    return 0;
                }    
        }
    }
    printf("0\n");

}