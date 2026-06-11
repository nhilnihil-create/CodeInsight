#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  int i, n, score[1000];
  double alpha = 0, m = 0;

  while(1){
    cin >> n;
    if(n == 0) break;
    else{
      for(i = 0; i < n; i++){
        cin >> score[i];
        m += score[i];
      }
      m = m / n;
      for(i = 0; i < n; i++){
        alpha += pow(score[i] - m, 2.0);
      }
      alpha = sqrt(alpha / n);
    }
    cout << fixed << setprecision(8) << alpha << endl;
    alpha = 0;
    m = 0;
  }
  return 0;
}