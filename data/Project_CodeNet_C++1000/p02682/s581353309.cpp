#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define loop(i,start, stop) for(int i = start; i < (stop); i++)
using namespace std;

int main(){
  
  int A,B,C,K;
  cin >> A >> B >> C >> K;

  int ans=0;

  if(K <= A) ans += 1 * K; 
  else if(A < K) {
    if (K-A <= B) ans += 1 * A + 0;
    else if (B < K-A) ans += 1 * A + 0 + (-1 * (K-A-B));
  }

  cout << ans << endl;

  return 0;
}
