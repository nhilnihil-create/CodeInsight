#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
using namespace std;


int main(void) {

  int n;
  while(cin >> n){
    if( n == 0 ) break;

    vector<double> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    double ave = accumulate(s.begin(), s.end(), 0.0) / n;

    double sgm = 0.0;
    for(int i=0; i<n; i++){
      sgm += ( s[i] - ave )*(s[i] - ave);
    }
    sgm /= n;

    double sd = sqrt(sgm);

    // cerr << " " << ave << " " << sgm << " " << sd << endl;

    printf("%.8lf\n", sd);

  }


  return 0;
}