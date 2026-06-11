#include <bits/stdc++.h>
#include <boost/foreach.hpp>
using namespace std;
#define pi 2*asin(1.0)
#define MAX 10000000
#define MOD 1000000007
#define _GLIBCXX_DEBUG


/////////////////////////


//Answer


int main() {
long N,flag=0;
cin>>N;
for(long i=1;i<10;i++){
    if(N%i==0&&N/i<10){
        flag=1;
        break;
    }
}
if(flag){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}


}

