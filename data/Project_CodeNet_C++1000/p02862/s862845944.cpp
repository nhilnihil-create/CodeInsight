#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)
#define MAX 10000000
#define MOD 1000000007


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

long fact(long N){
    if(N==0){
        return 1;
    }else{
        long ans=1;
        for(long i=1;i<N+1;i++){
        ans=ans*i;
        }
        return ans;
    }

}

/////////////////////////


//Answer


int main() {

Cominit();
long X,Y,x,y;
cin>>X>>Y;
if((2*Y-X)%3!=0||(2*X-Y)%3!=0){
  cout<<0<<endl;
}else{
x=(2*Y-X)/3;
y=(2*X-Y)/3;
long N=x+y;
long M=x;
long ans;
ans=facComb(N,M);
cout<<ans<<endl;
}


}



//高精度要求→しつこくlong doubleでcast　出力はprintf("20.20Lf")とかで
//printf("%a.bLf")のとき、a-b-1が整数部分の桁数。
/*配列系の書き方
long N;
cin>>N;
vector<long> p(N);
for(long i=0;i<N;i++){
cin>>p.at(i);
}

vector<int> d(102,1);

sort(A.begin(),A.end());
reverse(A.begin(),A.end());

typedef pair<long,long> P;
vector<P> p(N);
vector<vector<vector<long>>> dp(N+1,vector<vector<long>>(W+1,vector<long>(K+1)));
vector<vector<long>> A(N,vector<long>(M));

int a='A'+2;
cout<<a<<endl;　//a=67 文字は整数型に代入して文字コード化できる。

  char c=65;
cout<<c<<endl;  //c='A' 整数は文字型に代入してその整数が文字コードとしてあらわす整数にできる。

*/