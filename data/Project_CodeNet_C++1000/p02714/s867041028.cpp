#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end()
using namespace std;

int main() {
int N;cin >> N;
long long A = 0, B = 0, C = 0, count = 0;
vector<char> V(N);

for(int i = 0; i < N; i++){
cin >> V[i];
if(V[i] == 'R')A++;
if(V[i] == 'G')B++;
if(V[i] == 'B')C++;
}

for(int i = 0; i < N; i++){
for(int j = 1 + i; j < N; j++){

if(2*j - i < N){
    
    if(V[i] != V[j] && V[i] != V[2*j - i] && V[2*j - i] != V[j])count++;

}

}}

cout << A*B*C - count;
}