#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S;
    cin>>S;
    long long int nowmod=0;
    long long int rui10mod=1;
    long long int modnum[2030]={0};
    modnum[0]++;
    for(int i=S.size()-1;0<=i;i--){
        nowmod=(nowmod+rui10mod*(S[i]-'0'))%2019;
        modnum[nowmod]++;
        rui10mod=(rui10mod*10)%2019;
    }
    long long int ans=0;
    for(int i=0;i<2030;i++){
        ans+=modnum[i]*(modnum[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
