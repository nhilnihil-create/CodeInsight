#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  int N;
  cin >> N;
  
  if(N%2==0)
    cout << N/2 << endl;
  else
    cout << N/2+1 <<endl;
}