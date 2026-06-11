#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end()
using namespace std;

int main() {
long long int N, Ans = 0, total = 0;cin >> N;
map<long long int, long long int> P;
map<long long int, long long int> Q;
vector<long int> V(N);

for(int i = 0; i < N; i++){
cin >> V[i];
P[V[i]]++;
}

for(auto i : P)
total += ( P[i.first]*(P[i.first] - 1) )/2;


    for(auto i : P)
    Q[i.first] = total - ( P[i.first]*(P[i.first] - 1) )/2 + ( (P[i.first] - 1)*(P[i.first] - 2) )/2;
    

for(auto i : V)cout << Q[i] << endl;

}