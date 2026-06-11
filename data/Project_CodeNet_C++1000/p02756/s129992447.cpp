#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
string S;cin >> S;

ll N, count = 0;cin >> N;

deque<char> D(S.size());

rep(i, 0, S.size())D[i] = S[i];

rep(i, 0, N){
  
    ll T;cin >> T;

    if(T == 1)count++;

    if(T == 2){

    ll F;cin >> F;
    char C;cin >> C;

        if(F == 1){

            if(count%2 == 0)D.push_front(C);

            else D.push_back(C);

        }

        if(F == 2){

            if(count%2 == 0)D.push_back(C);

            else D.push_front(C);

        }

    }
 
}

if(count%2 == 1)reverse(ALL(D));

rep(i, 0, D.size())cout << D[i];
}