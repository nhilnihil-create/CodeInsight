#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> edge[600005];
int ans[600005];
int main(){
    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b+150000);
        edge[a+150000].push_back(b+300000);
        edge[a+300000].push_back(b);
    }
    int S,T;
    cin>>S>>T;

    for(int i=0;i<600005;i++)ans[i]=2100000000;
    queue<int> Qx,Qte;
    Qx.push(S);
    Qte.push(0);
    while(!Qx.empty()){
        int a,b;
        a=Qx.front();
        b=Qte.front();
        Qx.pop();
        Qte.pop();
        for(int i=0;i<edge[a].size();i++){
            if(ans[edge[a][i]]>b+1){
                ans[edge[a][i]]=b+1;
                Qx.push(edge[a][i]);
                Qte.push(b+1);
            }
        }
    }
    if(ans[T]==2100000000){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans[T]/3<<endl;
    return 0;
}
