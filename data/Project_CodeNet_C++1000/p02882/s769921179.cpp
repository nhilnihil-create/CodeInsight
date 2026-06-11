#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const double pi = 3.141592653589793238;

/*int main(){
  double a, b, x;
  cin >> a >> b >> x;
  double hx = x / a / a;
  double facex = a * hx;
  const double facemax = a * b;
  double degree = 0;
  cout << facex << endl;
  cout << endl;
  while (a*sin(degree/180*pi)<=b*sin((pi/2)-(degree/180*pi))){
    double facei = facemax - ((a*sin(degree/180*pi)*a*cos(degree/180*pi)));
    cout << degree << endl;
    cout << facei << endl;
    cout << endl;
    if (facei <= facex){
      cout << degree << endl;
      return 0;
    }
    degree++;
  }
  while (degree<=90){
    double facei = (a*sin(degree/180*pi)*a*cos(degree/180*pi)) / 2;
    cout << degree << endl;
    cout << facei << endl;
    cout << endl;
    if (facei <= facex){
      cout << degree << endl;
      return 0;
    }
    degree++;
  }
  return 0;
}*/

int main(){
  double a, b, x;
  cin >> a >> b >> x;
  double s = x/a;
  double rad;
  if (s >= a * b / 2){
    double h = (2*(a*b-s))/a;
    rad = atan2(h,a);
  }
  else {
    double w = 2*s/b;
    rad = atan2(b,w);
  }
  double deg = (rad/(2*pi)) * 360;
  printf("%.10f\n", deg);
  return 0;
}
