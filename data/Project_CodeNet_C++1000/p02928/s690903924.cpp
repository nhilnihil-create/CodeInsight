#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> num(n);
    vector<long long> zentai(n,0);
    vector<long long> ato(n,0);
    
    for(int i=0;i<n;i++){
        cin>>num.at(i);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(num.at(i)>num.at(j)){
                zentai.at(i)++;
                if(i<j){
                    ato.at(i)++;
                }
            }
        }
    }
    
    long long ans=0;
    
    for(int i=0;i<n;i++){
        ans+=ato.at(i)*k;
        ans%=1000000007;
        
        long long kake=((k-1)*(k)/2)%1000000007;
        
        ans+=zentai.at(i)*kake;
        ans%=1000000007;
    }
    
    cout<<ans<<endl;
}
