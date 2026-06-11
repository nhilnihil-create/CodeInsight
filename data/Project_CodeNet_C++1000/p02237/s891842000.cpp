#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 100000

int main(){
  int n;
  cin >>n;
  int A[n+2][n+2]={0};
  int t,k,l;
  for(int i=1;i<=n;i++){
    cin >> t >> k;
    for(int j=1;j<=k;j++){
      cin >> l;
      A[i][l]=1;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(j-1) cout << " ";
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
