#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793238462643383279;
int main(){
 int N; cin >> N; 
 vector<double> x(N); vector<double> y(N);
  for(int i = 0; i < N; i++){ cin >> x[i] >> y[i];}
  double ans = 0.0;
  for(int i = 0; i < 100100; i++){
    double s = cos((double)(i*pi)/5050);
    double t = sin((double)(i*pi)/5050);
    double X = 0.0; double Y = 0.0;
    for(int i = 0; i < N; i++){
      if( x[i]*s + y[i]*t >= 0){ X += x[i]; Y += y[i];}
    }
  ans = max(ans, sqrt(X*X+Y*Y));}
  
  cout << fixed << setprecision(15) << ans << endl; return 0;}
    