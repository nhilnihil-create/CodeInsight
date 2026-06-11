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
    vector<queue<int>> q(N);
    int a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            cin >> a; a--;
            q[i].push(a);
        }
    }
    int d = 0;
    int cnt = 0;
    queue<int> dq;
    set<int> se;
    for (int i = 0; i < N; i++) {
        if(!q[i].empty() && !q[q[i].front()].empty() && !q[q[q[i].front()].front()].empty() && q[q[q[i].front()].front()].front() == q[i].front() && q[q[i].front()].front() == i){
            se.insert(i);
        }
    }
    while(cnt < N*(N-1)){
        if(se.size() == 0){
            printf("%d\n", -1);
            return 0;
        }
        for (int v : se){
            q[v].pop(); dq.push(v); cnt++;
        }
        d++;
        se.clear();
        while(!dq.empty()){
            int v = dq.front(); dq.pop();
            if(!q[v].empty() && !q[q[v].front()].empty() && !q[q[q[v].front()].front()].empty() && q[q[q[v].front()].front()].front() == q[v].front() && q[q[v].front()].front() == v){
                se.insert(v); se.insert(q[v].front());
            }
        }
    }

    printf("%d\n", d);
    

}