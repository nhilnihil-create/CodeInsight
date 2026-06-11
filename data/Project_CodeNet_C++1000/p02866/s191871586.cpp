#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int ll;

const int MAX_N =100001;
const ll MOD = 998244353;
int N;

int main(){
  cin >> N;
  vector<ll>vec;
  for(int i = 0 ; i < N; i++){
    int d; cin >> d;
    vec.push_back(d);
  }

  if(vec[0] != 0){
    cout << 0 << endl;
    return 0;
  }

  for(int i = 1 ; i < N ; i++){
    if(vec[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  
  sort(vec.begin(), vec.end());

  ll res = 1;
  ll pre = 0;
  ll count = 1;
  ll pre_count = 1;
  
  for(int i = 1 ; i < vec.size() ; i++){
    if(pre != vec[i]){
      if(pre + 1 != vec[i]){
        cout << 0 << endl;
        return 0;
      }
      ll num = 1;
      for(int  j = 0 ; j < count ; j++){
        num = (num * pre_count) % MOD;
      }
      res = (res * num) % MOD;
      pre = vec[i];
      pre_count = count;
      count = 0;
    }
    count++;
  }
  ll num = 1;
  for(int  j = 0 ; j < count ; j++){
    num = (num * pre_count) % MOD;
  }
  res = (res * num) % MOD;
  cout << res << endl;
  return 0;
}
