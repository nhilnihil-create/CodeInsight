#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    long long int lis[200003];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        long long int a,b;
        cin>>a>>b;
        lis[i]=b*1000000+a;
    }
    sort(lis,lis+N);
    int flg=1;
    long long int now=0;
    for(int i=0;i<N;i++){
        now+=lis[i]%1000000;
        if(lis[i]/1000000<(long long int)now){
            flg=0;
            break;
        }
    }
    if(flg)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
