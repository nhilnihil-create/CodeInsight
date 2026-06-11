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
vector<long> Primelist;
//template functions
/////////////////////////
void Prinit(){
long PR=10000001;
vector<long> P(PR,0);
for(long i=2;i*i<PR;i++){
    if(P.at(i)==0){
        long j=i;
      j+=i;
        while(j<PR){
            P.at(j)=1;
             j+=i;         
        }
    }
}

for(long i=2;i*i<PR;i++){//Primelist.size()=446
    if(P.at(i)==0){
        Primelist.push_back(i);
    }
}
}

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
long N,K;
cin>>N>>K;
vector<long> A(N);
vector<long> F(N);
long maxA=0,maxF=0;;
for(long i=0;i<N;i++){
cin>>A.at(i);
if(maxA<A.at(i)){
    maxA=A.at(i);
}
}
for(long i=0;i<N;i++){
cin>>F.at(i);
if(maxF<F.at(i)){
    maxF=F.at(i);
}
}
sort(A.begin(),A.end());
sort(F.begin(),F.end());
reverse(A.begin(),A.end());
long ok=maxA*maxF;
long ng=-1;
while(labs(ok-ng)>1){
    long mid=(ok+ng)/2;
    long L=K;
    long t=0;
    for(long i=0;i<N;i++){
        if(A.at(i)*F.at(i)>mid&&L>=0){
            t=(A.at(i)*F.at(i)-mid);
            t=upDiv(t,F.at(i));
            L=L-t;
        }
    }
    if(L<0){
        ng=mid;
    }else{
        ok=mid;
    }
}

cout<<ok<<endl;

}



