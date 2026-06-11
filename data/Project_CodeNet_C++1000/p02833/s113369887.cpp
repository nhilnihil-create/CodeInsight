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
/////////////////////////



//Answer


int main() {

long long N;
cin>>N;
if(N%2==1){
    cout<<0<<endl;
}else{
    long long count=0;
	long long M=10;
    for(int i=1;N>=M;i++){
       count+=N/M;
      M=M*5;
    }
    cout<<count<<endl;
}

}