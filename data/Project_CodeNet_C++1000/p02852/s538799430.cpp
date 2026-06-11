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

int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    int t = N;
    vector<int> ans;
    int pt = N;
    while(t > 0){
        for (int i = M; i > 0; i--) {
            if(t - i >= 0 && S[t-i] == '0'){
                ans.push_back(i);
                t = t - i;
                break;
            }
        }
        if(pt == t){
            printf("-1\n");
            return 0;
        }
        pt = t;
    }
    int L = ans.size();
    for (int i = L-1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("\n");


}