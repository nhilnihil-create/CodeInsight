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
    int N;
    cin >> N;
    int M = N + 10000;
    vector<bool> a(M, true);
    a[0] = false; a[1] = false;
    for (int i = 2; i*i <= M; i++) {
        if(a[i]){
            for (int j = i; i*j <= M; j++) {
                a[i*j] = false;
            }
        }
    }

    for (int i = N; i < M; i++) {
        if(a[i]){
            printf("%d\n", i);
            break;
        }
    }


}