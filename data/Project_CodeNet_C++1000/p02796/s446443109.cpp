#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 100000;
const int MAX_V = 1000000000;
int N;
int X[MAX_N];
int L[MAX_N];
void input(){
scanf("%d", &N);
for(int i = 0; i < N; ++i){
scanf("%d%d", X + i, L + i);
}
}
P ps[MAX_N];
int solve(){
for(int i = 0; i < N; ++i){
ps[i] = P(X[i] + L[i], X[i] - L[i]);
}
sort(ps, ps + N);
int cur = -MAX_V;
int ans = 0;
for(int i = 0; i < N; ++i){
if(cur <= ps[i].second){
ans++;
cur = ps[i].first;
}
}
return ans;
}
int main(){
input();
int ans = solve();
printf("%d\n", ans);
return 0;
}