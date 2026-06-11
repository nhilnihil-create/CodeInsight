#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int cal_digit(int N, int K){
  int count = 0;
  while(N >0){
    N /= K;
    count++;
  }
  return count;
}

int main(){
  int n,k;
  cin >> n >> k;
  cout << cal_digit(n,k) << endl;
}