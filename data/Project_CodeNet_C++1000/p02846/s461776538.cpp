#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  long t1,t2,a1,a2,b1,b2;
  cin >> t1>>t2>>a1>>a2>>b1>>b2;
  long k=t1*a1;
  long m=t1*b1;
  long l=k+t2*a2;
  long n=m+t2*b2;
  if((m-k>0&&n-l>0)||(m-k<0&&n-l<0)){
    cout<<0<<endl;
  }
  else if(n-l==0){
    cout<<"infinity"<<endl;
  }
  else{
    if(abs(m-k)%abs(n-l)==0){
      cout<<abs(m-k)/abs(n-l)*2<<endl;
    }
    else{
      cout<<abs(m-k)/abs(n-l)*2+1<<endl;
    }
  }

}