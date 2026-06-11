#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end()
using namespace std;

int main() {
int N, Ans = 0;cin >> N;
string S;
map<string, int> P;
for(int i = 0; i < N; i++){
cin >> S;
P[S]++;
}

for(auto x : P){
Ans++;
}
cout << Ans << endl;
}