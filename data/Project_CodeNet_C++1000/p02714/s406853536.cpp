#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N;
    string S;
    long long ans=0;
    int i,j,k;

    long long r=0,g=0,b=0;

    cin>>N;
    cin>>S;

    for(i=0;i<N;i++){
        if(S[i] == 'R')r++;
        if(S[i] == 'G')g++;
        if(S[i] == 'B')b++;
    }

    ans=r*g*b;

    for(i=1;i<=N;i++){
        for(j=i;j<=N;j++){
            k=j+j-i;
            if(k <= N && i<=k){
                if(S[i-1] == S[j-1])continue;
                if(S[i-1] == S[k-1])continue;
                if(S[j-1] == S[k-1])continue;
                ans=ans-1;
            }
            
        }
    }
    
    cout<<ans<<endl;

    return 0;
}