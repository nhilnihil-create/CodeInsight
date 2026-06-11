#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int indeg[10000],s,t,V,E;
vector<int> A[10000];
bool flag[10000]={false};
vector<int> ans;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

void bfs(int a){
    queue<int> Q;
    Q.push(a);
    flag[a]=true;

    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        ans.push_back(u);

        for(int i=0;i<A[u].size();++i){
            --indeg[A[u][i]];
            if(indeg[A[u][i]]==0 && flag[A[u][i]]==false){
                flag[A[u][i]]=true;
                Q.push(A[u][i]);
            }
        }
    }

}

void tp_srt(){
    
    for(int i=0;i<V;++i){
        if(indeg[i]==0 && flag[i]==false){
            bfs(i);
        }
    }
}

int main(){
    
    cin>>V>>E;
    Fill(flag,false);

    
    for(int i=0;i<E;++i){
        cin>>s>>t;
        A[s].push_back(t);
    }
    
    for(int i=0;i<V;++i){
        for(int j=0;j<A[i].size();++j){
            ++indeg[A[i][j]];
        }
    }
    
    tp_srt();

    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<"\n";
    }

}
