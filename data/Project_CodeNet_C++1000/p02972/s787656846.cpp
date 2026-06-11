#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Answer = 0;cin >> N;
vector<ll> V(N);
vector<bool> Ans(N, 0);

rep(i, 0, N)cin >> V[i];

for(ll i = N - 1; i >= N/2; i--){

     if(V[i] == 1)Ans[i] = 1;

     if(V[i] == 0)Ans[i] = 0;

}

for(ll i = N/2 - 1; i >= 0; i--){

    ll a = 2, count = 0;

    while(a*(i + 1) <= N){

        if(Ans[a*(i + 1) - 1] == 1)count++;

        a++;
    
    }

    if(count%2 == V[i])Ans[i] = 0;

    else Ans[i] = 1;
}

ll a = 1;

for(auto ans : Ans ){

    if(ans)Answer++;

}

cout << Answer << endl;

for(auto ans : Ans ){

    if(ans)cout << a << " ";

    a++;
}

}