#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100000],s,ans,p[100000];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s^=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=60;j>=0;j--){
            if(((s>>j)&1)==0){
                if((a[i]>>j)&1){
                    if(p[j]==0){p[j]=a[i];break;}
                    else a[i]^=p[j];
                }
            }
        }
    }
    for(int i=60;i>=0;i--){
        if(((ans>>i)&1)^1)ans^=p[i];
    }
    cout<<ans+(ans^s)<<endl;
}
