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
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    bool check = true;

    for (ll i = A; i < C-1; i++) {
        if(S[i-1] == '#' && S[i] == '#'){
            check = false;
        }
    }
    for (ll i = B; i < D-1; i++) {
        if(S[i-1] == '#' && S[i] == '#'){
            check = false;
        }
    }
    if(check == false){
        No();
        return 0;
    }
    if(D < C){
        check = false;
        for (ll i = B; i <= D; i++) {
            if(S[i-2] == '.' && S[i-1] == '.' && S[i] == '.'){
                check = true;
            }
        }
    }
    if(check == false){
        No();
        return 0;
    }
    if(check == true){
        Yes();
        return 0;
    }
    

}