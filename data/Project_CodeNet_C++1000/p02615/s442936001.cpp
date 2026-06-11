#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(void){
  int num;
  cin >> num;
  vector<long long> friendly(num);
  for(int i = 0;i < num;i++){
    cin >> friendly[i];
  }
  sort(friendly.begin(),friendly.end());
  long long ans = 0;
  for(int i =0;i < num-1;i++){
    int p = (3+i)/2;
    ans = ans+ friendly[num-p];
  }
  cout << ans << endl;
  return 0;
}
