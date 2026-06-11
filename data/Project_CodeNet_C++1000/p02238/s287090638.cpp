#include <iostream>
using namespace std;
 
int visit[100],end[100],a[100][100];
int t,N,u,k,p;
 
void list(int N){
    for(int i=0;i<N;i++){
        cin>>u>>k;
        for (int j=0;j<k;j++){
            cin>>p;
            a[u-1][p-1]=1;
        }
    }
}
 
void sor(int cur,int N){
    t+=1;
    visit[cur]=t;
    for(int kyo=0;kyo<N;++kyo){
        if(a[cur][kyo]==1&&visit[kyo]==0){
            sor(kyo,N);
        }
    }
    t+=1;
    end[cur]=t;
}
 
int main(){
    cin >> N;
    list(N);
    for(int i=0;i<N;i++){
        if(visit[i] == 0) sor(i,N);
    }
    for(int i=0;i<N;i++){
        cout<<i+1<<' '<<visit[i]<<' '<<end[i]<<endl;
    }
}
