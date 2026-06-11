#include <iostream>

using namespace std;

int main()
{
    long long int N,sum=0;
    cin>>N;
    long long int num[N+1];
if(N>=1&&N<=1000000){
    for(int i=1;i<=N;i++){
    num[i]=i;
    if(i%3>=1&&i%5>=1){
        sum+=i;
    }
    }
    cout<<sum;
}
    return 0;
}