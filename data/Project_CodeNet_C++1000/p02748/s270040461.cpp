#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,M;
  cin>>A>>B>>M;
  vector<int> reizouko(A);
  vector<int> renji(B);
  priority_queue<int, vector<int>, greater<int>> minA;
  priority_queue<int, vector<int>, greater<int>> minB;
  priority_queue<int, vector<int>, greater<int>> price;
  for(int i=0; i<A; i++){
    int a;
    cin>>a;
    reizouko.at(i)=a;
    minA.push(a);
  }
  for(int i=0; i<B; i++){
    int b;
    cin>>b;
    renji.at(i)=b;
    minB.push(b);
  }

  price.push(minA.top()+minB.top());
  for(int i=0; i<M; i++){
    int x, y, c;
    cin>>x>>y>>c;
    price.push(reizouko.at(x-1)+renji.at(y-1)-c);
  }
  cout << price.top() << endl;
}
