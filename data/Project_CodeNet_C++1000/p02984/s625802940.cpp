#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N;cin >> N;
vector<ll> V(N);
vector<ll> Ans(N);

rep(i, 0, N){

    cin >> V[i];

    if(i%2 == 0)Ans[0] += V[i];

    else Ans[0] -= V[i];

}

rep(i, 0, N - 1){

    Ans[i + 1] = 2*V[i] - Ans[i];

}

for(auto ans : Ans )cout << ans << " ";

}