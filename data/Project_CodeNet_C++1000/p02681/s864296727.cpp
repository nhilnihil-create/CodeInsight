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
  
  string S,T;
  cin >> S >> T;

  loop(i,0,S.size()){
    if (S[i] != T[i]) {no return 0;}
  }

  yes

  return 0;
}
