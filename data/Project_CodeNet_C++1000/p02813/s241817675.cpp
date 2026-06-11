#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n), q(n), temp(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
    temp[i] = i + 1;
  }
  
  int a = 1; 
  do{
     if(p == temp) break;
     a++;
  }while(next_permutation(temp.begin(), temp.end()));
         
  for(int i = 0; i < n; i++){
    cin >> q[i];
    temp[i] = i + 1;
  }
  
  int b = 1; 
  do{
     if(q == temp) break;
     b++;
  }while(next_permutation(temp.begin(), temp.end()));
  
  cout << abs(a - b);
  return 0;
}
