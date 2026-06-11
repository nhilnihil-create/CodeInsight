#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<pair<double, pair<long long, long long>>> angle_xy(N);
  for(int i = 0; i < N; i++){
    long long x, y;
    cin >> x >> y;
    double angle;
    if(x == 0 && y == 0){
      angle = 0;
    }else{
      angle = atan2(y, x);
    }
    angle_xy[i] = make_pair(angle, make_pair(x, y));
  }
  sort(angle_xy.begin(), angle_xy.end());

  long long ans_sq = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      long long x_sum = 0, y_sum = 0;
      if(i <= j){
        for(int k = i; k <= j; k++){
          x_sum += angle_xy[k].second.first;
          y_sum += angle_xy[k].second.second;
        }
      }else if(i > j){
        for(int k = i; k <= j + N; k++){
          x_sum += angle_xy[k % N].second.first;
          y_sum += angle_xy[k % N].second.second;
        }
      }
      ans_sq = max(ans_sq, x_sum * x_sum + y_sum * y_sum);
    }
  }

  long double ans = sqrt(static_cast<long double>(ans_sq));
  cout << setprecision(50) << ans << endl;

}
