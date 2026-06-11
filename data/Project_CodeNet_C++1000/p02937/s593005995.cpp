#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S,T;
    cin>>S>>T;
    vector<int> lis[30];
    for(int i=0;i<S.size();i++){
        lis[S[i]-'a'].push_back(i+1);
    }
    long long int ans=0,now=0;

/*
    for(int i=0;i<30;i++){
        printf("%c:",'a'+i);
        for(int j=0;j<lis[i].size();j++){
            printf("[%d]",lis[i][j]);
        }
        puts("");
    }
*/

    for(int i=0;i<T.size();i++){
        if(lis[T[i]-'a'].size()==0){
            puts("-1");
            return 0;
        }
        int mo=T[i]-'a';
        if(lis[mo][lis[mo].size()-1]<=now){
            //printf("[%d]",i);
            ans+=S.size()-now;
            ans+=lis[T[i]-'a'][0];
            now=lis[T[i]-'a'][0];
        }
        else{
            int l=0,r=lis[mo].size(),mid;
            for(int j=0;j<20;j++){
                mid=(l+r)/2;
                if(now<lis[mo][mid])r=mid;
                else l=mid;
            }
            if(now>=lis[mo][mid])mid++;
            ans+=lis[mo][mid]-now;
            now=lis[mo][mid];
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
