#include<bits/stdc++.h>
using namespace std;
  
 
int main(){
  std::vector<int> v;
  for(int i=0;i<3;i+=1){
       int x;
       cin >> x;
          v.push_back(x);
  }
  sort(v.begin(),v.end());
  cout << v[0]+v[1] << endl;
     
}