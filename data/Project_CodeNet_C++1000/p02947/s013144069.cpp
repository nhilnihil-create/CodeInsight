#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, Ans = 0;cin >> N;
map<string, ll> MAP;
for(ll i = 0; i < N; i++){
string s;cin >> s;
sort(ALL(s));
MAP[s]++;
}

for(auto x : MAP){
Ans += (x.second*(x.second - 1))/2;
}
cout << Ans;
}
