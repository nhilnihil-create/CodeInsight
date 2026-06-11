#include <bits/stdc++.h>
using namespace std;

int main() {

  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  int x, y, c;
  int minA =1000000;
  int minB =1000000;

  for(int i=0;i<A;i++){
    cin >> a.at(i);
    if(a.at(i)<minA){
      minA = a.at(i);
    }
  }

  for(int i=0;i<B;i++){
    cin >> b.at(i);
    if(b.at(i)<minB){
      minB = b.at(i);
    }
  }

  int min = minA + minB;

  for(int i=0;i<M;i++){
    cin >> x >> y >> c;
    int num = a.at(x-1) + b.at(y-1) - c;
    if(num < min){
      min = num;
    }
  }

   cout <<  min << endl;
}