#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
  int N;
  double sum, ave;
  vector<double> out;
  while(cin >> N && N){
    sum = 0;
    vector<int> v(N);
    for(int i=0;i<N;i++){
      cin >> v[i];
      sum += v[i];
    }
    ave = sum / N;
    sum = 0;
    for(int i=0;i<N;i++){
      sum += pow(v[i]-ave, 2.0);
    }
    sum = sqrt(sum/N);
    out.push_back(sum);
  }
  for(int i=0;i<out.size();i++){
    cout << fixed << setprecision(10) << out[i] << endl;
  }

  return 0;
}