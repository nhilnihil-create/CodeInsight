#include <bits/stdc++.h>
using namespace std;
void alert(vector<int> vec){
  for(int i=0; i<vec.size(); i++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(vec.size()-1) << endl;
}

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  int n = N/max(H,W);
  if(N%max(H,W)!=0) n++;
  cout << n << endl;
}