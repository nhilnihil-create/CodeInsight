#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int l[500000],r[500000];
int main(){
    string S;
    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S[i]=='<')l[i+1]=l[i]+1;
    }
    for(int i=S.size();0<=i;i--){
        if(S[i]=='>')r[i]=r[i+1]+1;
    }
    long long int ans=0;
    for(int i=0;i<S.size()+1;i++)ans+=(long long int)max(l[i],r[i]);
    cout<<ans<<endl;
    return 0;
}
