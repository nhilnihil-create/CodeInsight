#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,a=0,b=0,c=0,Z=1,Q=1000000007;
  cin>>N;
  for(int64_t i=0;i<N;i++){
    int64_t x;
    cin>>x;
    if(a==x){
      a++;
      if(b==x){
        if(c==x){
          Z=(Z*3)%Q;
        }
      else{
        Z=(Z*2)%Q;
      }
    }
    }
    else if(b==x){
      b++;
      if(c==x){
        Z=(Z*2)%Q;
      }
    }
    else if(c==x){
      c++;
    }
    else{
      Z=0;
    }
  }
  cout<<Z<<endl;
}