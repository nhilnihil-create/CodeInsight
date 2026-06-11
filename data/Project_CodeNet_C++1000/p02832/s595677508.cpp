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

long N;
long now=1;
long count=0;
cin>>N;
vector<long> A(N);
for(long i=0;i<N;i++){
cin>>A.at(i);
if(A.at(i)==now){
now++;
}else{
count++;
}
}

if(now>1){
cout<<count<<endl;
}else{
  cout<<-1<<endl;
}

}
