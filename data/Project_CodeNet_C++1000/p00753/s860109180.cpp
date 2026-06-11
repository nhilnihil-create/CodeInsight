#include <iostream>
#define REP(i,n) for(int i = 0;i<(n);i++)

using namespace std;
const int N = 300000;
int p[N+1];
void e() {
  fill(p,p+N,1);
  p[0]=p[1]=0;
  for(int i=2;i*i<=N;i++)
    if(p[i])for(int j=i*i;j<=N;j+=i)p[j]=0;
}
int main() {
  int n;
  e();
  REP(i,N)p[i+1] += p[i];
  while (cin >> n, n) {
    cout << p[2*n] - p[n] << endl;
  }
}