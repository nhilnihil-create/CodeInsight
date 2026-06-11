#include <bits/stdc++.h>
using namespace std;

double siguma2(double *s);
double n;

int main(){
  cout << fixed << setprecision(8);
  while(1){

  cin >> n;
  if(n == 0) break;
  double s[1000] = {};
  for(int i = 0;i < n;i++){
    cin >> s[i];
  }
  double answer = 0;
  answer = sqrt(siguma2(s) / n);
  cout << answer << endl;
}
return 0;
}

double siguma2(double *s){
  double sum = 0;
  double avg;
  for(int i = 0;i < n;i++){
    sum += s[i];
  }
  avg = sum / n;
  sum = 0;
  for(int i = 0;i < n;i++){
    sum += pow(s[i] - avg,2);
  }
  return sum;
}

