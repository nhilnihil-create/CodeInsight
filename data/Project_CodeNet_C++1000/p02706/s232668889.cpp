#include <iostream>

using namespace std;

int main()
{
    long long int N,M;
    cin>>N>>M;
    long long int A[M];
    long long int tot=0;
if(N>=1&&M>=1&&N<=1000000&&M<=10000){
    for(int i=0;i<M;i++){
        cin>>A[i];
        if(A[i]<=10000&&A[i]>=1){
        tot+=A[i];
        }
    }
    if(tot<=N){
        cout<<N-tot;
    }
    else{
        cout<<-1;
    }
}
    return 0;
}