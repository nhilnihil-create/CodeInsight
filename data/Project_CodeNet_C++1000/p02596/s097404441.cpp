#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll K, Ans = 0;cin >> K;
bool C = 1;
map<ll, bool> M;

ll num = 0;
  
if(K%2 == 0)C = 0;

while(C){

  Ans++;num *= 10;num += 7;num %= K;

  if(num == 0)break;

  if(M[num]){C = 0;break;}

  M[num] = 1;

}

if(C)cout << Ans;

if(!C)cout << -1;

}