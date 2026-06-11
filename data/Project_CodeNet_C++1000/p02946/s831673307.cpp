#include<iostream>
#include<vector>
using namespace std;

int main(){
  int K,X; cin >> K >> X;
  vector<int>ans;
  for(int i=X-K+1;i<X+K;i++){
    if(i != X+K-1)  cout << i << ' ';
    else  cout << i << endl;
  }
}
