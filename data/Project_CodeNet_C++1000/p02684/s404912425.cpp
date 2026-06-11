#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,count,next,loopnum,startloop,p;
    long long int k;
    cin>>n>>k;
    int a[n],l[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        l[i]=0;
    }
    count=next=1;
    while(1){
        if(l[next-1]==0){
            l[next-1]=count;
            count++;
            next=a[next-1];
        }
        else{
            loopnum=count-l[next-1];
            startloop=l[next-1];
            break;
        }
    }
    if(k+1-startloop<0)p=k+1;
    else p=(k+1-startloop)%loopnum+startloop;
    for(int i=0;i<n;i++){
        if(l[i]==p){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}