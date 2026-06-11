#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A,B;
  cin >> A >> B;
  int x;
  int sum = 0;
  int count = 1;
  rep(i,A){
    cin >> x;
    sum += x;
    if(sum > B){
     break; 
    }
   count++; 
  }
  cout << count << endl;
}
