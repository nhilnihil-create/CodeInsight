#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    long long a,b;
    long long ans=0;
    for(long long i=1;i<=N;i++){
        ans+=i*(N+1-i);
    }
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        if(a>b){
            ans-=b*(N+1-a);
        }else{
            ans-=a*(N+1-b);
        }
    }

    cout<<ans<<endl;

    return 0;
}