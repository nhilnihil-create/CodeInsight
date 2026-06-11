#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

vector<int> node[100000];

void getdepth(int depth,int id,int out[]){
    out[id] = depth;
    for(int i = 0;i < node[id].size();i++){
        getdepth(depth + 1,node[id][i],out);
    }
}

int main(void){
    int n;
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        int id,k;
        scanf("%d%d",&id,&k);
        for(int j = 0;j < k;j++){
            int c;
            scanf("%d",&c);
            node[id].pb(c);
        }
    }

    int parent[n];
    for(int i = 0;i < n;i++){
        parent[i] = -1;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < node[i].size();j++){
            parent[node[i][j]] = i;
        }
    }

    vector<int> root;
    for(int i = 0;i < n;i++)
        if(parent[i] == -1){
            root.pb(i);
        }

    int depth[n];
    for(int i = 0;i < root.size();i++)
        getdepth(0,root[i],depth);

    for(int i = 0;i < n;i++){
        printf("node %d: parent = %d, depth = %d, ",i,parent[i],depth[i]);
        if(parent[i] == -1)
            printf("root");
        else if(node[i].size())
            printf("internal node");
        else
            printf("leaf");
        printf(", [");
        for(int j = 0;j < node[i].size();j++){
            printf("%d",node[i][j]);
            if(j < node[i].size() - 1)
                printf(", ");
        }
        printf("]\n");
    }
    return 0;
}