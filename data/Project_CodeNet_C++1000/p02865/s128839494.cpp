#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//　ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const int mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int gcd(int a, int b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}


// ll memo[2020][2020];
// int pascal_triangle(){
//   for(int i = 0; i < 2020; i++){
//     for(int j = 0; j < i+1; j++){
//       if(j == 0 || j == i) memo[i][j] = 1;
//       else{
// 	memo[i][j] = (memo[i-1][j-1]+memo[i-1][j]);
//       }
//     }
//   }
//   return 0;
// }


int factorial(int n){
  if(n == 0) return 1;
  return n*factorial(n-1);
}

int divisor(int a){
  int cnt = 0;
  for(int i=1; i <= a; i++) if(a%i == 0) cnt++;
  return cnt;
}

int comb(int n, int k){
  return factorial(n) / (factorial(n-k)*factorial(k));
}

int answer(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}






int main(){
  int N;
  cin >> N;
  cout << (N-1)/2 << endl;
  
  return 0;
}







