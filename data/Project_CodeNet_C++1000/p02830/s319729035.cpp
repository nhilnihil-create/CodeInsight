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
cin>>N;
string A,B;
cin>>A>>B;

for(long i=0;i<N;i++){

cout<<A.at(i)<<B.at(i);
 
}

cout<<endl;

}
