#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int MOD=1000000007;

int main() {
  int M,D,ans=0;
  cin >> M >>D;
  for(int i=1; i<=M; i++){
    for(int j=10; j<=D; j++){
      if(i==(j/10)*(j%10) && j/10>=2 && j%10>=2){
        ans +=1;
      }
    }
  }
  cout << ans << endl;
}