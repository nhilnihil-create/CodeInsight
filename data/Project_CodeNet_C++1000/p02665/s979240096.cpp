#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctype.h>
#include<string>
#include<cmath>
#include<string.h>
#include<sstream>
using namespace std;

int N;
vector<int> leaf;
vector<long long> min0,max0;

int main(){
    cin>>N;
    leaf.resize(N+1);
    min0.resize(N+1);
    max0.resize(N+1);
    for(int i=0;i<N+1;++i){
        cin>>leaf[i];
    }
    min0[N]=leaf[N];
    max0[N]=leaf[N];
    for(int i=N-1;i>=0;--i){
        min0[i]=(min0[i+1]+1)/2+leaf[i];
        max0[i]=max0[i+1]+leaf[i];
    }
    if(min0[0]>1)cout<<-1<<endl;
    else{
        long long cur=1;
        long long vertex=0;
        for(int i=0;i<N+1;++i){
            vertex+=cur;
            cur-=leaf[i];
            if(i<N)cur=min(cur*2,max0[i+1]);
        }
        cout<<vertex<<endl;
    }
    return 0;
}
