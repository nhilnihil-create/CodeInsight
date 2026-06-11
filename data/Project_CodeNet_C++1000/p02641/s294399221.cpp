#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  int a,x,n,y;
  cin >> x >> n;
  if(n==0){
    cout << x << endl;
    return 0;
  }
  vector<int> row(n);
  for(int i=0;i<n;i++){
    cin >> row[i];
  }
  int sa[3]={0,-1,1};
  for(int i=0;i<100;i++){
    for(int j=0;j<=2;j++){
      for(int k=0;k<n;k++){
        int y = x + sa[j] * i ;
        a = count(row.begin(), row.end(), y);
        if(a == 0){
          cout << y << endl;
          return 0;
        }
      }
    }
  }
  
}                                                                                                                                                     