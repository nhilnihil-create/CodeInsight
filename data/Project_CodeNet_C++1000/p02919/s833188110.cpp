#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> P_inv(N + 1);
  for(int i = 1; i <= N; i++){
    int tmp;
    cin >> tmp;
    P_inv[tmp] = i;
  }

  long long ans = 0;
  set<int> indices;
  indices.insert(0);
  indices.insert(N + 1);
  for(int i = N; i >= 1; i--){
    //cout << P_inv[i] << endl;
    auto larger1 = indices.lower_bound(P_inv[i]);
    //auto larger1 = lower_bound(indices.begin(), indices.end(), P_inv[i]);
    auto smaller1 = prev(larger1);
    //cout << (*smaller1) << ' ' << (*larger1) << endl;
    if((*larger1) != N + 1){
      auto larger2 = next(larger1);
      ans += static_cast<long long>(i) * (P_inv[i] - *smaller1) * (*larger2 - *larger1);
    }
    if((*smaller1) != 0){
      auto smaller2 = prev(smaller1);
      ans += static_cast<long long>(i) * (*smaller1 - *smaller2) * (*larger1 - P_inv[i]);
    }
    indices.insert(P_inv[i]);
    //cout << ans << endl;
  }
  
  cout << ans << endl;
}
