#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;
  vector<int> A(N);
  bool p = false,m = false;
  long long sum = 0;
  for(int i = 0;i < N;i++) {
    cin >> A.at(i);
    if(A.at(i) > 0) p = true;
    if(A.at(i) < 0) m = true;
    sum += A.at(i);
  }

  sort(A.begin(),A.end());
  if(p && !m) {
    cout << sum - A.at(0)*2 << endl;
    for(int i = 1;i < N-1;i++) {
      cout << A.at(0) << " " << A.at(i) << endl;
      A.at(0) -= A.at(i);
    }
    cout << A.at(N-1) << " " << A.at(0) << endl;
  }else if(!p && m) {
    reverse(A.begin(),A.end());
    cout << sum*(-1) + A.at(0)*2 << endl;
    for(int i = 1;i < N;i++) {
      cout << A.at(0) << " " << A.at(i) << endl;
      A.at(0) -=  A.at(i);
    }
  }else {
    int num = 0;
    sum = 0;
    for(int i = 0;i < N;i++) {
      if(A.at(i)<0) sum -= A.at(i);
      else sum += A.at(i);
      if(i < N-1 && A.at(i) < 0 && A.at(i+1) >= 0) num = i;
    }
    cout << sum << endl;

    for(int i = num+1;i < N-1;i++) {
      cout << A.at(num) << " " << A.at(i) << endl;
      A.at(num) -= A.at(i);
    }
    
    for(int i = 0;i <= num;i++) {
      cout << A.at(N-1) << " " << A.at(i) << endl;
      A.at(N-1) -= A.at(i);
    }
  }



}
