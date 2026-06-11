#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<bool>v(3,false);
  for(int X=0;X<2;X++){
    int A;
    cin>>A;
    v[A-1]=true;
  }
  for(int X=0;X<3;X++){
    if(v[X]==false){
      cout<<X+1<<endl;
    }
  }
}