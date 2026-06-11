#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define rep(i,n) for(i=0;i<=N;i++)
int i=0;
int main(){
    int N;
    cin>>N;
    rep(i,N){
        int sum=0;
        sum=(int)(i*1.08);
        if(sum==N){
            cout<<i;
            return 0;
        }else{
            ;
        }
    }
    cout<<":(";
    return 0;
}
