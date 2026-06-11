#include<iostream>
using namespace std;

int main(){
    int N,i=1,count=0;
    cin>>N;
    int a[N];
    for(int i=1;i<=N;++i)cin>>a[i];

        while(i<=N){
            if(a[i]%2==1)count++;
            i+=2;
        }
    cout<<count;
}