#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    long long int ans=0;
    int N;
    int nowt=1;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(nowt==a){
            nowt++;
        }
        else{
            ans++;
        }
    }
    if(nowt==1)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
