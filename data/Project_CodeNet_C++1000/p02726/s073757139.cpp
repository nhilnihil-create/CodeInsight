#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

queue<ll> Q;
vector<vector<ll>> V;
map<ll, ll> Ans;
vector<ll> A;

void bfs(){

    if(!Q.empty()){

        ll x = Q.front();

        Q.pop();

        rep(i, 0, V[x].size()){

            if(A[V[x][i]] != -1)continue;
            
            Q.push(V[x][i]);

            A[V[x][i]] = A[x] + 1;Ans[A[x]]++;

        }

        bfs();

        
    }
}

int main(){
ll N, X, Y;cin >> N >> X >> Y;

V.resize(N);
A.resize(N);

rep(i, 0, N){

    if(i != 0)V[i].push_back(i - 1);

    if(i != N - 1)V[i].push_back(i + 1);

}

V[X - 1].push_back(Y - 1);V[Y - 1].push_back(X - 1);

rep(i, 0, N){

    rep(j, 0, N){

        A[j] = -1;

    }

    Q.push(i);A[i]++;

    bfs();

}

rep(i, 0, N - 1){
  
  cout << Ans[i]/2 << endl;
  
}

}
