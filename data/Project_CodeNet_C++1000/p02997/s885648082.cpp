#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  int n,k;
  cin >> n >> k;
  vector<vector<int>> l(n+1);  
  if(k > (n-1)*(n-2)/2){
    cout << -1;
  }else{
    int c = (n-1)*(n-2)/2 -k;
    //cout << c << endl;
    int r = 0;
    int m =0;
    for(int i = 2;i<n+1;i++){
      l[1].push_back(i);
      m++;
    }
    
    for(int i = 2;i<n+1;i++){
      for(int j =i+1;j<n+1;j++){
        if(c==0){break;}
        l[i].push_back(j);
        r++;
        m++;
        if(r == c){break;}
      }
      if(r == c){break;}
    }
    cout << m << endl;
    //cout << m << endl
    for(int i = 1;i<n+1;i++){
      for(int j = 0;j<l[i].size();j++){
        cout << i << " " << l[i][j] << endl;
      }
    }
  }
}