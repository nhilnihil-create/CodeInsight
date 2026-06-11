#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A,B;
  cin >> A >> B;
  int x;
  int sum = 0;
  rep(i,B){
    cin >> x;
    sum += x;
  }
  if(A <= sum){
    cout << "Yes" << endl;
  }
else{
cout << "No" << endl;
}
 
}
