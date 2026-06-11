#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, Y;
  cin >> X >> Y;
  int Ans=max(0, 400000-X*100000)+max(0, 400000-Y*100000);
  if(X==1 && Y==1){
    Ans+=400000;
  }
  cout << Ans << endl;
}