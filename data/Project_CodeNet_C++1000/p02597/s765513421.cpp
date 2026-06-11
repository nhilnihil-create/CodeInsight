#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  char c[N];
  int num=0;
  for(int i=0;i<N;i++){
    cin >> c[i];
    if(c[i]=='R') num++;
  }
  int ans = 0;
  for(int i=0;i<num;i++){
    if(c[i]!='R') ans++;
  }
  cout << ans << endl;
}
