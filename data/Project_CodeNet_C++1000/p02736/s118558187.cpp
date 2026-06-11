#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll N;
    cin >> N;
    vector<char> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    bool check = true;

    for (ll i = 0; i < N; i++) {
        if(a[i] == '2'){
            check = false;
            break;
        }
    }

    ll f;
    if(check){
        f = 0;
        for (ll i = 0; i < N; i++) {
            if((N - 1) == ( i | (N - i - 1) )){
                if(a[i] == '3'){
                    f++;
                }
            }
        }

        if(f % 2 == 0){
            printf("0\n");
            return 0;
        }
        else{
            printf("2\n");
            return 0;
        }
    }

    f = 0;
    for (ll i = 0; i < N; i++) {
        if((N - 1) == ( i | (N - i - 1) )){
            f += a[i] - '0';
        }
    }
    if(f % 2 == 0){
        printf("0\n");
    }
    else{
        printf("1\n");
    }

}
