#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,C;
  C=0;
  cin>>A >>B;
  while(C*A - C + 1 < B){
   C++;
  }
cout << C << endl;
}
