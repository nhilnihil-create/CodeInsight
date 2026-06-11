#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double pi = 3.141592653589793;

struct Cordinate{
  double x;
  double y;
};

void kock( int n, Cordinate p1, Cordinate p2 ){
  if( n==0 ){
    return;
  }

  Cordinate s, t, u;
  s.x = (2*p1.x+1*p2.x)/3;
  s.y = (2*p1.y+1*p2.y)/3;
  t.x = (1*p1.x+2*p2.x)/3;
  t.y = (1*p1.y+2*p2.y)/3;
  u.x = (t.x-s.x)*cos(pi/3)-(t.y-s.y)*sin(pi/3)+s.x;
  u.y = (t.x-s.x)*sin(pi/3)+(t.y-s.y)*cos(pi/3)+s.y;

  kock( n-1, p1, s );
  cout << fixed << setprecision(8) << s.x << " " << setprecision(8) << s.y << endl;
  kock( n-1, s, u );
  cout << fixed << setprecision(8) << u.x << " " << setprecision(8) << u.y << endl;
  kock( n-1, u, t );
  cout << fixed << setprecision(8) << t.x << " " << setprecision(8) << t.y << endl;
  kock( n-1, t, p2 );
}

int main(){
  int n;
  cin >> n;

  Cordinate p1, p2;
  p1.x = 0, p1.y = 0;
  p2.x = 100, p2.y = 0;

  cout << fixed << setprecision(8) << p1.x << " " << setprecision(8) << p1.y << endl;
  kock( n, p1, p2 );
  cout << fixed << setprecision(8) << p2.x << " " << setprecision(8) << p2.y << endl;

  return 0;
}
