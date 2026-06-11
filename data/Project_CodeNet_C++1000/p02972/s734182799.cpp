#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  vector<int> v(N);
  vector<int> ans(N);
  vector<int> ret;

  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  for(int i = N-1; i >= 0; i--){
    int num = i + 1;

    int sum = 0;
    for(int j = 2; num * j <= N; j++){
      sum += ans[num*j-1];
    }
    if(v[i] == (sum % 2)){
      ans[i] = 0;
    } else { 
      ans[i] = 1;
      ret.push_back(num);
    }
  }
  if(ret.size() == 0){
    cout << 0 << endl;
  } else { 
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); i++){
      if(i == ret.size() - 1){
        cout << ret[i] << endl;
      } else { 
        cout << ret[i] << " ";
      }
    }
  }
}
