#include <iostream>

using namespace std;

int main(){
    int a,b,c,K,sum=0;
    cin>>a>>b>>c>>K;
    if(K-a<=0)cout<<K<<"\n";
    else if(K-a-b<=0)cout<<a<<"\n";
    else cout<<a+(K-a-b)*-1<<"\n";
}