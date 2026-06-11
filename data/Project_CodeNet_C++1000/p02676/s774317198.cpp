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
  
  int K;
  string S;
  cin >> K >> S;

  if (S.size() <= K){cout << S << endl;}
  else{
    loop(i,0,K)
      cout << S[i];
    cout << "..." << endl;
  }

  return 0;
}
