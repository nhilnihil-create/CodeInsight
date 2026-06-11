#include <bits/stdc++.h>
using namespace std;



int main(){
    double A,B;
    cin>>A>>B;
    double Amax=A+1; double Bmax=B+1;
    A=A/0.08;
    Amax=Amax/0.08;
    B=B/0.1;
    Bmax=Bmax/0.1;
  double product=ceil(max(A,B));
    if(product>=Amax||product>=Bmax){
    cout<<"-1"<<endl;
    }else{
    cout<<product<<endl;
    }
    
  
}
