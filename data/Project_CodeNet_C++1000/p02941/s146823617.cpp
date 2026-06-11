#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
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
    vector<int> A(N), B(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> B[i];
    }

    priority_queue<iint> q;
    for (ll i = 0; i < N; i++) {
        q.push(make_pair(B[i], i));
    }

    ll ans = 0;
    while(!q.empty()){
        iint v = q.top(); q.pop();
        int s = v.first; int t = v.second;

        if(B[(t-1+N) % N] + B[(t+1)%N] < B[t]){
            ans += B[t] / (B[(t-1+N) % N] + B[(t+1)%N]);
            B[t] = B[t] % (B[(t-1+N) % N] + B[(t+1)%N]);
            if(B[t] < A[t]){
                if((A[t] - B[t]) % (B[(t-1+N) % N] + B[(t+1)%N]) != 0){
                    printf("-1\n"); return 0;
                }
                else{
                    ans -= (A[t] - B[t]) / (B[(t-1+N) % N] + B[(t+1)%N]);
                    B[t] = A[t];
                }
            }
            else if(B[t] == A[t]){

            }
            else{
                q.push(make_pair(B[t], t));
            }
        }
        else{

        }

    }

    for (int i = 0; i < N; i++) {
        if(A[i] != B[i]){
            printf("-1\n"); return 0;
        }
    }
    printf("%lld\n", ans);


}