#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  int n,m;
  cin >> n>>m;
  
  int l[n+1][2] = {0};
  int p;
  string s;
  
  
  for(int i = 0;i < m;i++){
    cin >> p >> s;
    if(s == "AC" &&  l[p][0] == 0){
      l[p][0] +=1; 
    }else if(s == "WA" && l[p][0] == 0){
      l[p][1] += 1;
    }
  }
  int a,w;
  a = 0;
  w = 0;
  for(int i = 1;i < n+1;i++){
    a += l[i][0];
    if(l[i][0] > 0){
      w += l[i][1];
    }
    
    //cout << a << " " << w << endl;
  }
  
  cout << a << " " << w << endl;
 }