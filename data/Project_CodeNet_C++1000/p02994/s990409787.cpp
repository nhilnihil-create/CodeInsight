#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,L;
    cin>>N>>L;
    int ans=N*L+((N-1)*N)/2;
    if(L<=0&&0<=L+N-1){

    }
    else if(L+N-1<0){
        ans-=L+N-1;
    }
    else if(0<L){
        ans-=L;
    }
    cout<<ans<<endl;
    return 0;
}
