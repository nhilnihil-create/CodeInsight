#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int X;
  int Y;
  cin >> N;
  cin >> X;
  cin >> Y;

  int k[N+1];
  for(int i=1;i<=N;i++)k[i]=0;
  int line[3];
  int m;
  for(int i=1; i<N; i++){
    for(int j=i+1; j<=N; j++){
      line[0] = j - i;
      line[1] = abs(X-i)+abs(Y-j)+1;
      line[2] = abs(Y-i)+abs(X-j)+1;
      m=min(line[0],min(line[1],line[2]));
      k[m]++;
    }
  }
  for(int i=1; i<N; i++){
    cout << k[i] << endl;
  }

}