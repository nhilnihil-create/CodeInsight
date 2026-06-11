#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<pair<int, int>> g;
int main() {
  long long a,v,b,w,t;
  cin >>a >>v>>b>>w>>t;
  
  if((v*t-w*t)- abs(a-b)>= 0){
    cout << "YES";
  }else{
   cout << "NO";
  }
  
  
}
