#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    vector<string>S(N);for(long long i=0;i<N;i++)cin>>S[i];
    sort(S.begin(),S.end());
    long long times=1;
    long long tmp=1;
    for(long long i=1;i<N;i++){
        if(S[i]==S[i-1]){
            tmp++;
        }
        else{
            times=max(times,tmp);
            tmp=1;
        }
    }
    times=max(times,tmp);
    tmp=1;
    for(long long i=0;i<N;i++){
        if(i>0){
            if(S[i]==S[i-1]){
            tmp++;
            }
            else{
                tmp=1;
            }
        }
        if(tmp==times){
            cout<<S[i]<<endl;
        }
    }
    return 0;
}