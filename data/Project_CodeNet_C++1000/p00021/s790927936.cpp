#include <iostream>
#include <complex>
using namespace std;

#define P complex<double>

// e·éë·Ã
#define EPS (1e-10)
// 2ÂÌXJ[ªµ¢©Ç¤©
#define EQ(a,b) (abs((a)-(b)) < EPS)

// e·éë·Ã
#define EPS (1e-10)
// 2ÂÌXJ[ªµ¢©Ç¤©
#define EQ(a,b) (abs((a)-(b)) < EPS)

// OÏ (cross product) : a~b = |a||b|sinÆ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

// 2¼üÌ½s»è : a//b <=> cross(a, b) = 0
bool is_parallel(P a1, P a2, P b1, P b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}


int main(){
  int n;
  P a,b,c,d;

  cin >> n;
  for( int loop=0;loop<n;loop++ ){
    cin >> a.real() >> a.imag();
    cin >> b.real() >> b.imag();
    cin >> c.real() >> c.imag();
    cin >> d.real() >> d.imag();

    P x=a-b, y=c-d;
    x = x/abs(x);
    y = y/abs(y);

    if( is_parallel( a,b,c,d ) )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}