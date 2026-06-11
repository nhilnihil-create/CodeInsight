#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  long long sum=1;
  long long oba=1;
  int P=0;
  bool huro=false;bool mu=false;
  for(int X=0;X<N;X++){
    long long I;cin>>I;string size=to_string(I);P+=size.size()-1;
    if(I==0){
      mu=true;
      break;
    }
    sum*=I;oba*=I;
    if(sum/1000000000000000001!=0){
      huro=true;
    }
    sum%=1000000000000000001;
  }
  if(mu==true)cout<<0<<endl;
  else if(sum==1000000000000000000)cout<<1000000000000000000<<endl;
  else if(huro==true||P>=18)cout<<-1<<endl;
  else cout<<sum<<endl;
}