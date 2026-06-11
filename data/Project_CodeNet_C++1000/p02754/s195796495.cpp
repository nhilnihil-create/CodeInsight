#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,A,B;
  cin >> N >> A >> B;
  int64_t answer=0;
  
  int64_t r;
  r= N % (A+B);
  
  if(r >= A)
  answer += (N/(A+B))*A + A;
  else
  answer += (N/(A+B))*A + r ;
  
  cout << answer << endl;
}
