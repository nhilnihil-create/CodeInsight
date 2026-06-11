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
    map<string, int> S;
    string t;
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if(S.count(t)){
            S[t]++;
            m = max(m, S[t]);
        }
        else{
            S[t] = 1;
            m = max(m, 1);
        }
    }
    for(auto v : S){
        auto a = v.first;
        auto b = v.second;
        if(b == m){
            printf("%s\n", a.c_str());
        }
    }

}