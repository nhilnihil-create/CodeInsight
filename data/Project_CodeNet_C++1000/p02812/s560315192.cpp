#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A;
  cin >> A;
  int B = A - 2;
  string S;
  cin >> S;
  int count = 0;
  rep(i,B){
    int n = i + 1;
    int m = i + 2;
    if(S[i] == 'A' && S[n] == 'B' && S[m] == 'C'){
       count++;
       }
       }
       cout << count << endl;
}
