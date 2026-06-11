#include<iostream>
using namespace std;

int main(){
  int h1, h2, m1, m2, k;
  int t1, t2;
  int time;

  cin >> h1 >> m1 >> h2 >> m2 >> k;

  t1 = h1 * 60 + m1;
  t2 = h2 * 60 + m2;

  time = t2 - t1;


  if (time <= k) cout << "0" << endl;
  else{
    time -= k;
    cout << time << endl;
  }

  return 0;
}
