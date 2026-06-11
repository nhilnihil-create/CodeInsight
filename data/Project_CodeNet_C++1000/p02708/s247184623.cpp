#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, K, total = 0, Ans = 0;cin >> N >> K;
vector<ll> f;
vector<ll> b;

rep(i, 0, N + 1){

    total += i;total%=1000000007;

    if(i >= K - 1)f.push_back(total);

}

total = 0;

for(ll i = N; i >= 0; i--){

    total += i;

    if(i <= N - K + 1)b.push_back(total);
    
}

rep(i, 0, N - K + 2){

   if(b[i] - f[i] + 1 > 0){Ans += (b[i] - f[i] + 1)%1000000007;Ans%=1000000007;}
  
   else break;
  
}
  
cout << Ans;
  
}