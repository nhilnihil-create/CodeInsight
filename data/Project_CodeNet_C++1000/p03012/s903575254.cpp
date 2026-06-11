#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nan(n);
    for(int i=0;i<n;i++){
        cin>>nan.at(i);
    }
    
    long int ans=1000000;
    for(int i=0;i<n;i++){
        long int minta=0;
        long int maxta=0;
        for(int k=0;k<=i;k++){
            minta+=nan.at(k);
         
        }
        for(int h=i+1;h<n;h++){
            maxta+=nan.at(h);

        }
        long int h=abs(maxta-minta);
        ans=min(ans,h);


    }
    cout<<ans<<endl;
}