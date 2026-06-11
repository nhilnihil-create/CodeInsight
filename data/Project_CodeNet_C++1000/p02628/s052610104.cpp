#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){

    int N,K,ans=0;
    int p[1001];
    cin>>N>>K;
    for(int i=0;i<N;i++)    cin>>p[i];

    for(int i=0;i<N-1;i++){
        for(int j=i;j<N;j++){
            if(p[i]>p[j]){
                int a=p[i];
                p[i]=p[j];
                p[j]=a;
            }
        }
    }

    for(int i=0;i<K;i++)    ans+=p[i];
    cout<<ans<<endl;
    return 0;
}