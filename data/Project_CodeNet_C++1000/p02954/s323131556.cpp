#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S;
    cin>>S;
    int ans[100000]={0};
    int cou=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='R')cou++;
        else{
            ans[i-1]+=(cou+1)/2;
            ans[i]+=cou/2;
            cou=0;
        }
    }
    cou=0;
    for(int i=S.size();0<=i;i--){
        if(S[i]=='L')cou++;
        else{
            ans[i+1]+=(cou+1)/2;
            ans[i]+=cou/2;
            cou=0;
        }
    }
    for(int i=0;i<S.size();i++){
        cout<<ans[i];
        if(i!=S.size()-1){
            cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}
