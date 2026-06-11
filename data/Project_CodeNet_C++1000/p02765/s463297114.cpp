#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  int N,R;
  
  cin>> N >> R;
  
  if(N>=10)
    cout << R << endl;
  else
    cout << R + 100*(10-N) <<endl;
}