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
  
  int N;
  cin >> N;

  if (N % 10 == 3) cout << "bon" << endl;
  else if (1 < N % 10 && N % 10 < 6) cout << "hon" << endl;
  else if (N % 10 == 7 || N % 10 == 9) cout << "hon" << endl;
  else cout << "pon" << endl;

  return 0;
}
