#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    long long H[N];cin>>H[0];
    for(long long i=1;i<N;i++){
        cin>>H[i];
    }
    for(long long i=N-1;i>=1;i--){
        if(H[i-1]>H[i]){
            if(H[i-1]-H[i]>=2){
                cout<<"No"<<endl;
                return 0;
            }
            else{
                H[i-1]--;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}