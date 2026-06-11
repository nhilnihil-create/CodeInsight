#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int count = 0;
  int X;
  for(int i = 0;i < A;i++){
    cin >> X;
   if(B <= X){
     count++;
   }
  }
  cout << count << endl;
}
