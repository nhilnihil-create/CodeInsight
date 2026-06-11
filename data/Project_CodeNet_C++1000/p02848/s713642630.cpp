#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int n=0;
    char x;
  vector<char> v;

  while(cin >> x){
    v.push_back(x);
    n++;
  }
  int z;
   for(int x=0;x<n;x++){
      z = int(v[x]);
     z=z-65+N;
     z%=26;
     z+=65;
     v[x]=(char)z;
       cout << v[x];
   }
   }