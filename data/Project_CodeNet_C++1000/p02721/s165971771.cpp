#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int N,K,C;
string S;
int main(void){
    cin>>N>>K>>C>>S;
    int work[2][K];
    memset(work,0,sizeof work);
    for(int day=0,cnt=0;day<N&&cnt<K;day++)if(S[day]=='o')work[0][cnt++]=day,day+=C;
    for(int day=N-1,cnt=0;day>=0&&cnt<K;day--)if(S[day]=='o')work[1][K-1-cnt++]=day,day-=C;
    for(int i=0;i<K;i++)if(work[0][i]==work[1][i])cout<<work[0][i]+1<<endl;
    return 0;
}