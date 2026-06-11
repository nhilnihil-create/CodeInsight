#include <bits/stdc++.h>
#include <boost/foreach.hpp>
using namespace std;
#define pi 2*asin(1.0)
#define MAX 10000000
#define MOD 1000000007
#define _GLIBCXX_DEBUG
 
vector<long> fac(MAX);
vector<long> finv(MAX);
vector<long> inv(MAX);
 
//template functions
/////////////////////////
void Cominit(){
  fac.at(0)=fac.at(1)=1;
  finv.at(0)=finv.at(1)=1;
  inv.at(1)=1;
  for(long i=2;i<MAX;i++){
      fac.at(i)=(fac.at(i-1)*i)%MOD;
      inv.at(i)=MOD-inv.at(MOD%i)*(MOD/i)%MOD;
      finv.at(i)=finv.at(i-1)*inv.at(i)%MOD;
  }
}

long facComb(long N,long M){// nCm%
if(N<M) return 0;
if(N<0||M<0) return 0;
return fac.at(N)*(finv.at(M)*finv.at(N-M)%MOD)%MOD;
}

long Comb(long N,long M){// nCm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
for(long i=M;i>0;i--){
    ans=ans/i;
}
return ans;
}

long Perm(long N,long M){// nPm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
return ans;
}

long GCM(long A,long B){
            long W,r;
    if(A<B){

        W=B;
        B=A;
        A=W;
    }
    while(A%B!=0){
        r=A%B;
        A=B;
        B=r;
    }
    return B;
}
long LCM(long A,long B){
    return (A*B)/GCM(A,B);
}

long upDiv(long a,long b){
  return (a+b-1)/b;
}

long strtolong(string str){
istringstream ss;
ss=istringstream(str);
long num;
ss>>num;
return num;
}

long chartolong(char ch){
long num;
num=ch-'0';
return num;
}

string longtostr(long N){
    string str;
    str=to_string(N);
    return str;
}









/////////////////////////


//Answer


int main() {

long A,B,C;
cin>>A>>B>>C;
if(A+B+C<=21){
cout<<"win"<<endl;
}else{
cout<<"bust"<<endl;
}

}

