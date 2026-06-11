#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;

ll a = 1;

while(floorl(N/(10*powl(5, a - 1))) >= 1){

Ans += floorl(N/(10*powl(5, a - 1)));

a++;
}

if(N%2 == 0)cout << Ans;

else cout << 0;


}
