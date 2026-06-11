#include <iostream>
 
using namespace std;
 
int main(){
    int N,a=0;
    long long int Aa=1,A[100010];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0){
            printf("0\n");
            a=1;
            break;
        }
    }
    if(a==0){for(int i=0;i<N;i++){
        if(Aa>1&&1000000000000000000/Aa<A[i]){
            printf("-1\n");
            a=1;
            break;
        }
        Aa*=A[i];
    }
    }
    if(a==0){
        printf("%lld\n",Aa);
    }
}