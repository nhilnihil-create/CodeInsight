#include <bits/stdc++.h>
using namespace std;

int main() {
 int N, L;
  cin >> N >> L;
  vector<int> all(N+1);
  int allsum = 0;
  for(int i = 1; i <= N; i++){
    all.at(i) = L+i-1;
    allsum += L+i-1;
  }
  if(L >= 1){
    cout << allsum -L << endl;
  } else {
    int Min = 10000;
    int cnt = 0;
    for(int i = 1; i<= N; i++){
      if(Min>abs(0-all.at(i))) cnt = i;
      Min = min(Min,abs(0-all.at(i)));
    }
     cout << allsum - all.at(cnt) << endl;
  }
               
                
                
                
                
}