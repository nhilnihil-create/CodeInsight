#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<climits>
#include<sstream>
using namespace std;
#define maxn 10010
struct Node{
    int x,y,val,pre;
};
Node g[100010];
int gh[maxn],du[maxn];
int n,m;
stack<int> s;

int main(){
    int i,j;
    cin>>n>>m;
    memset(gh,-1,sizeof gh);
    memset(du,0,sizeof du);
    for(i=0;i<m;i++){
        cin>>g[i].x>>g[i].y;
        g[i].pre=gh[g[i].x];
        gh[g[i].x]=i;

        du[g[i].y]++;
    }
    for(i=0;i<n;i++)
        if(du[i]==0)
            s.push(i);
    while(!s.empty()){
        int t=s.top();
        s.pop();
        cout<<t<<endl;
        j=gh[t];
        while(j!=-1){
            int yy=g[j].y;
            du[yy]--;
            if(!du[yy]) s.push(yy);
            j=g[j].pre;
        }
    }
    return 0;
}

