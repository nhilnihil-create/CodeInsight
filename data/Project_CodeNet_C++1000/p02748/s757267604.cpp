#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M;
  cin >> A >> B >> M;
  int rmin=114514;
  int wmin=114514;
  vector<int> R(A);
  vector<int> W(B);
  for(int i=0;i<A;i++){
    cin >> R.at(i);
    rmin=min(rmin,R.at(i));
  }
  
  for(int j=0;j<B;j++){
    cin >> W.at(j);
    wmin=min(wmin,W.at(j));
  }
  int r,w,C;
  int cost=rmin+wmin;
  for(int h=0;h<M;h++){
    cin >> r >> w >> C;
    cost = min(cost,R.at(r-1)+W.at(w-1)-C);
  }

  cout << cost << endl;
  
}

