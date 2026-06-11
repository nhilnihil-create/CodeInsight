#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
#define ll long long
#define ld long double

int main(){
  ll x;
  cin >> x;
  for(int i = -200; i <= 200; i++){
    for(int j = -200; j <= 200; j++){
      if((pow(i,5)-pow(j,5))==x){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}