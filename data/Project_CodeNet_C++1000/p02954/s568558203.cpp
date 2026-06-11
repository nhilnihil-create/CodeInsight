#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  vector<int> A(S.size(),0);
  int a=1,b=0,c=0;
  bool d=0;
  char C='R';
  for(int i=1;i<(int)S.size();i++){
    if(S[i]==C){
      if(C=='R'){
        if(d==1)
          a++;
        else
          b++;
      }else{
        if(d==0)
          A[c]++;
        else
          A[c-1]++;
      }
      d=1-d;
    }else{
      if(C=='R'){
        if(d==1){
          A[i]=a+1;
          A[i-1]=b;
        }else{
          A[i]=b+1;
          A[i-1]=a;
        }
        d=1;
        c=i;
      }else{
        a=1;
        b=0;
        d=0;
      }
    }
    C=S[i];
  }
  for(int i=0;i<S.size();i++){
    cout<<A[i];
    if(i==S.size()-1)
      cout<<endl;
    else
      cout<<' ';
  }
}