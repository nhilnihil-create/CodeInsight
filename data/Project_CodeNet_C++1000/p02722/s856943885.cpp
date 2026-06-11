#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t cnt=0;
    int64_t n,p,k;
    cin>>n;
    p=n;
    for(int64_t i=1;i<=sqrt(n);i++){
        if(i==1){
            cnt++;
            continue;
        }
       while(n%i==0){
           n=n/i;
           if(n%i==1)cnt++;
       }
        n=p;
    }
    // cout<<cnt<<" "<<sqrt(n)<<endl;
    for(int64_t i=1;i<=sqrt(p-1);i++){
       if(i==1&&(p-1)!=1){
           cnt++;
           continue;
       }
       if((p-1)%i==0&&(p-1)!=1){
           k=(p-1)/i;
           if(i==k){
               cnt++;
           }else cnt+=2;
       }
    }
    cout<<cnt;
}
