#include <bits/stdc++.h>
using namespace std;
#define MAX 123456*2
int main (){
    bool pr[MAX];
    int a;
    for(int i=0;i<MAX;i++) pr[i]=true;
    pr[0]=false;
    pr[1]=false;
     
    for(int i=0;i*i<MAX;i++){
        if(pr[i]){
            for(int j=i*i;j<=MAX;j=j+i){
                pr[j]=false;
            }
        }
    }
    while(cin>>a,a){
        int ans=0;
        for(int i=a+1;i<=2*a;i++){
            if(pr[i])ans++;
        }
        cout<<ans<<endl;
    }
}