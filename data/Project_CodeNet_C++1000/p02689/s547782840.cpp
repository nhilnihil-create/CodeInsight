#include <stdio.h>		// standard input output
#include <iostream>		// input output stream, cin cout( console in console out)
#include <cmath>		// circle math ( sin, con, sinh
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>		// input output manipulation​
using namespace std;
#define rep(i, n) for(int i = 1; i <= (int)n; i++)
#define ll long long

int main(){
  int N,M,ans;
  cin >> N >> M;
  int h[N],m[N];
  rep(i,N){
    cin >> h[i];
    m[i]=0;
  }
  rep(i,M){
    int A,B;
    cin >> A >> B;
    m[A]=max(m[A],h[B]);
    m[B]=max(m[B],h[A]);
  }

  rep(i,N){
    if(h[i]>m[i])
      ans++;
  }
  cout << ans << endl;
}
