#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int cou[200004];
vector<int> edge[200004];
int ans[200004];
void func(int pos,int nowcou,int bef){
    int nowans=nowcou+cou[pos];
    ans[pos]=nowans;
    for(int i=0;i<edge[pos].size();i++){
        if(edge[pos][i]!=bef)func(edge[pos][i],nowans,pos);
    }
}



int main(){
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=0;i<Q;i++){
        int a,b;
        cin>>a>>b;
        cou[a]+=b;

    }
    func(1,0,-1);

    for(int i=1;i<=N;i++){
        cout<<ans[i];
        if(i!=N)cout<<' ';
    }
    cout<<endl;
    return 0;
}
