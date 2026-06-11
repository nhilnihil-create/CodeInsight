#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)


//template functions
/////////////////////////
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

/////////////////////////


//Answer


int main() {

long N,flag=1;
string S;
cin>>N>>S;
if(N%2!=0){
    cout<<"No"<<endl;
}else{
    for(long i=0;i<N/2;i++){
        if(S.at(i)!=S.at(i+N/2)){
            flag=0;
            break;
        }  
    }
if(flag==0){
    cout<<"No"<<endl;
}else{
    cout<<"Yes"<<endl;
}

}




}