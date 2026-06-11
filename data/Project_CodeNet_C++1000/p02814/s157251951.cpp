#include<bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t x,int64_t y){
if(x==0 || y==0)
  return max(x,y);
  else{
  if(x<y)
    return gcd(x,y%x);
    else if(y<x)
      return gcd(y,x%y);
    else
      return x;
  }

}
int64_t lcm(int64_t x,int64_t y){
return (x*y)/gcd(x,y);
}
int main(){
int64_t N,M;
  cin>>N>>M;
  set<int>S;
  vector<int64_t>A(N);
  for(int64_t i=0;i<N;i++){
  int64_t a;
    cin>>a;
    a/=2;
     A.at(i)=a;
    int64_t s=0;
    for(int i=0; ;i++){
     if(a%2!=0){
        s=i; break;
     }else
         a/=2;
    }
    S.insert(s);
  }int m=S.size();
  if(m!=1)
    cout<<0<<endl;
  else{
    int64_t l=A.at(0);
    for(int i=1;i<N;i++){
      l=lcm(l,A.at(i));
      if(M<l){l=M+1; break;}
    }
    int64_t ans=((M/l)+1)/2;
    cout<<ans<<endl;
  
  }
    return 0;
}