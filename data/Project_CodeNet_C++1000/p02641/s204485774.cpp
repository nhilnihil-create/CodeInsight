#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define loop(i,start, stop) for(int i = start; i < (stop); i++)
using namespace std;

int main(){

  int X, N;
  cin >> X >> N;

  if (N == 0){
    cout << X << endl;
    return 0;
  }

  int p[102];
  int buf[102] = {0};
  loop(i,0,N) {
    cin >> p[i];
    buf[p[i]]++;
  }

  bool b_flag = false;
  bool b_flag1 = false;
  bool b_flag2 = false;
  int i=0;
  while(true){
    if(buf[abs(X)] == 0) b_flag = true;
    if(buf[abs(X+i)] == 0) b_flag1 = true;
    if(buf[abs(X-i)] == 0) b_flag2 = true;
    if(b_flag || b_flag1 || b_flag2) break;
    i++;
  }

  if(b_flag) cout << X << endl;
  else if(b_flag2) cout << X-i << endl;
  else if(b_flag1) cout << X+i << endl;

  return 0;
}