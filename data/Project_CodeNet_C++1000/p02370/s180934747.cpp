#include<vector>
#include<cstdio>
#define MAX 10000
using namespace std;
const int WHITE = 0,GRAY =1,BLACK = 2;

vector<int> G[MAX];
int color[MAX] = {WHITE};
vector<int> L;

void visit(int n){
    if(color[n] != BLACK){
        color[n] = BLACK;
        for(auto itr = G[n].begin();itr != G[n].end();++itr){
            visit(*itr);
        }
        
        L.insert(L.begin(),n);
    }
}
void topological(int v){
    while(1){
        for(int i = 0;i < v;++i){
            if(color[i] != BLACK){
                visit(i);
                break;
            }
            if(i == v-1) return;
        }
    }
}

int main(){
    int v,e,s,t;
    scanf("%d %d\n",&v,&e);
    for(int i = 0;i < e;++i){
        scanf("%d %d\n",&s,&t);
        G[s].push_back(t);
    }
    topological(v);

    for(int i = 0;i < v;++i){
        printf("%d\n",L[i]);
    }
}

