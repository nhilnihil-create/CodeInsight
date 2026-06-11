#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int main(){
    long long L,R;
    cin>>L>>R;    
    if(R-L>=2018){
        cout<<0;
        return 0;
    }
    long long ans=2019;
    for(long long i=L;i<R;i++){
        for(long long j=L+1;j<=R;j++){
            if((i*j)%2019<ans){
                ans=(i*j)%2019;
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}
