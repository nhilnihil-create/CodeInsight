#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p[1000005];
int main(){
    int k=7;
    int a;
    cin>>a;
    int ans=1;
    while(1){
        if(k<a){
            k*=10;
            k+=7;
            ans++;
        }
        else{
            k%=a;
            if(k==0){
                cout<<ans<<endl;
                return 0;
            }
            else if(p[k]){
                cout<<-1<<endl;
                return 0;
            }
        p[k]=1;
        }
    }
    return 0;
}