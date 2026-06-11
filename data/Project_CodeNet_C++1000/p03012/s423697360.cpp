 #include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  int sum = 0;
  for(int i = 0; i < n;i++){
    cin >> w.at(i);
    sum += w.at(i);
  }
  int mini = sum;
  int t_sum = 0;
for(int i = 0;i<n;++i){
  cin >> w.at(i);
  t_sum += w.at(i);
  mini = min(mini, abs(t_sum-(sum-t_sum)));
}
  cout << mini << endl;

}