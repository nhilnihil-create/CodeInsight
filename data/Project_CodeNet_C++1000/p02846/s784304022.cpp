#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  int64_t A=A1-B1;
  int64_t B=A2-B2;
  if((0<A&&0<B)||(A<0&&B<0))
    cout<<0<<endl;
  else if(A*T1+B*T2==0)
    cout<<"infinity"<<endl;
  else{
   if((0<A&&0<A*T1+B*T2)||(A<0&&A*T1+B*T2<0))
     cout<<0<<endl;
    else{
    int64_t a=abs(A*T1);
      int64_t b=abs(A*T1+B*T2);
      if(a%b==0)
        cout<<2*(a/b)<<endl;
      else
        cout<<2*(a/b)+1<<endl;
    
    
    }
  
  
  
  }
    return 0;
}
