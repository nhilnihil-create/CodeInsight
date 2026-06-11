#include <bits/stdc++.h>
using namespace std;
int main(){
  long N,D;
  long c=0;
 cin>>N>>D;
  long a,b;
  for(int i=0;i<N;i++){
  cin>>a>>b;
     
    if(a*a+b*b<=D*D){
    c++;
     // cout<<a*a+b*b<<endl;
  //    cout<<d[i][0];
    }
  }
  cout <<c<<endl;
  
}
