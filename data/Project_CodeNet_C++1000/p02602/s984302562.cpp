#include<iostream>
using namespace std;
long long N,K;
int main(){
    cin>>N>>K;
    long long A[N];
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=K;i<N;i++)cout<<((double)A[i]/A[i-K]>1LL?"Yes":"No")<<endl;
    return 0;
}