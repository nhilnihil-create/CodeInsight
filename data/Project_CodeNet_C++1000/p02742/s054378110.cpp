#include<bits/stdc++.h>
using namespace std;
int main(){
  long long H, W;
  cin >> H >> W;
  cout << ((H==1||W==1)?1:(H/2+H%2)*(W/2+W%2)+(H/2)*(W/2)) << endl;
}