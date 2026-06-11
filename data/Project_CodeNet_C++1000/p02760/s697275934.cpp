#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    vector<int> a(9);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    int N;
    cin >> N;
    int b;
    vector<bool> c(9,false);
    for (int i = 0; i < N; i++) {
        cin >> b;
        for (int j = 0; j < 9; j++) {
            if(a[j] == b){
                c[j] = true;
            }
        }
    }
    bool ans = false;
    for (int i = 0; i < 3; i++) {
        if(c[3*i] && c[3*i+1] && c[3*i+2]){
            ans = true;
        }
        if(c[i] && c[3+i] && c[6+i]){
            ans = true;
        }
    }
    if(c[0] && c[4] && c[8]){
        ans = true;
    }
    if(c[2] && c[4] && c[6]){
        ans = true;
    }
    if(ans){
        Yes();
    }
    else{
        No();
    }

}