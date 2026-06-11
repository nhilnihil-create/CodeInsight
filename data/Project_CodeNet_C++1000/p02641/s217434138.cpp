#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){

    int X,N,p[101];
    cin>>X>>N;

    if(N==0){
        cout<<X<<endl;
        return 0;
    }

    for(int i=0;i<N;i++)    cin>>p[i];

    int ans=X;

    for(int i=1;i<=105;i++){
        for(int j=0;j<N;j++){
            if(ans==p[j])   break;
            else if(j==N-1){
                cout<<ans<<endl;
                return 0;
            }            
        }
        if(i%2==0){
            ans+=i;
        }else{
            ans-=i;
        }
    }

    return 0;
}