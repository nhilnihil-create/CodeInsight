#include<bits/stdc++.h>
using namespace std;

int main(){
    double x1,y1,x2,y2;

    double dis;
  
  cin >> x1 >> y1 >> x2 >> y2;

  dis = ((double)x1 - x2) * ((double)x1 - x2) + ((double)y1 - y2) * ((double)y1 - y2);
  dis = sqrt(dis);

  cout << fixed << setprecision(12) << dis << endl;
  
  return 0;
}

