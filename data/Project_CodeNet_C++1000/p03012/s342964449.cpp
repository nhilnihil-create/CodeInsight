#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;
typedef long long ll;

int main(){
  int N;
  vector<int> W;
  cin >> N;
  for(int i=0;i<N;i++){
    int n;
    cin >> n;
    W.push_back(n);
  }
  int sum = accumulate(W.begin(),W.end(), 0);
  int a=0;
  int ans =100;
  int dif;
  for(int i=0;i<N;i++){
    a += W[i];
    dif = abs(sum-2*a);
    if(ans>dif) ans=dif;
  }
  cout << ans << endl;
}
