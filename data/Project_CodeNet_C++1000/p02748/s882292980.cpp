#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, M;
  cin >> A >> B >> M;
  int Mina=1000000, Minb=1000000;
  vector<int> a(A), b(B), x(M), y(M), c(M);
  for(int i=0; i<A; i++){
    cin >> a.at(i);
    Mina=min(Mina, a.at(i));
  }
  for(int i=0; i<B; i++){
    cin >> b.at(i);
    Minb=min(Minb, b.at(i));
  }
  for(int i=0; i<M; i++){
    cin >> x.at(i) >> y.at(i) >> c.at(i);
  }
  int Ans=Mina+Minb;
  for(int i=0; i<M; i++){
    Ans=min(Ans, a.at(x.at(i)-1)+b.at(y.at(i)-1)-c.at(i));
  }
  cout << Ans << endl;
}