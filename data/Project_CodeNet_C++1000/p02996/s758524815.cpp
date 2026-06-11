#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, T = 0;cin >> N;
vector<pair<ll, ll>> V(N);
   
rep(i, 0, N)cin >> V[i].second >> V[i].first;

sort(ALL(V));

for(auto x : V){

T += x.second;

if(T > x.first){cout << "No";exit(0);}

}

cout << "Yes";

}