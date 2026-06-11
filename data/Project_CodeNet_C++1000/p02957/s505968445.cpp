#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0;
    cin>>a>>b;
    for(long long i=0;i<max(a,b);i++){
    if(abs(a-i)==abs(b-i)){cout<<i; return 0;}
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
