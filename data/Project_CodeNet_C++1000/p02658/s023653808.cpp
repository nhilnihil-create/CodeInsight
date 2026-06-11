#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,seki=1;
    cin>>n;
    long long int a[n];

    for(long long int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }

    for(long long int i=0;i<n;i++){
        if(a[i]<=1000000000000000000/seki){
            seki*=a[i];
        }else{
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<seki<<endl;
    
}