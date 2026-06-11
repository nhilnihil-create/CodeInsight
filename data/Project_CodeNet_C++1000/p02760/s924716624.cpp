#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool check(vector<int> A){
  if(A.at(0)==-1 && A.at(1)==-1 && A.at(2)==-1) return true;
  if(A.at(3)==-1 && A.at(4)==-1 && A.at(5)==-1) return true;
  if(A.at(6)==-1 && A.at(7)==-1 && A.at(8)==-1) return true;
  if(A.at(0)==-1 && A.at(3)==-1 && A.at(6)==-1) return true;
  if(A.at(1)==-1 && A.at(4)==-1 && A.at(7)==-1) return true;
  if(A.at(2)==-1 && A.at(5)==-1 && A.at(8)==-1) return true;
  if(A.at(0)==-1 && A.at(4)==-1 && A.at(8)==-1) return true;
  if(A.at(2)==-1 && A.at(4)==-1 && A.at(6)==-1) return true;
  
  return false;
}

int main() {
  vector<int> A(9);
  rep(i, 9) cin >> A.at(i);
  int N;
  cin >> N;
  rep(i, N){
    int x;
    cin >> x;
   rep(i, 9) if(A.at(i) == x) A.at(i)=-1;
  }
  if(check(A)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


