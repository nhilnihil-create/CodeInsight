#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(void){
    // Your code here!
int l,r;
cin>>l>>r;

if((r-l)>=2019){
    cout<<0<<endl;
    return 0;
}

long long  answer=1e9;
for(long long i=l;i<r;i++){
    for(long long j=i+1;j<=r;j++){
        answer= min((i*j)%2019,answer);
    }
}
cout<<answer;
}
