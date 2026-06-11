#include <iostream>
#include <vector>
#include <queue>


using namespace std;

typedef long long ll;
typedef vector<vector<int> > Graph;

int main(int argc, const char * argv[]) {
    
    int N;
    cin>>N;
    
    Graph g;
    g.resize(N);
    
    //vector<int> color(N,0);  //0:未訪問 1:発見 2:訪問済み
   
    int ans[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<N-1;++i){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    int X,Y;
    cin>>X>>Y;
    --X;
    --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
    
    for(int i=0;i<N;++i){
        vector<int>  dist(N,-1);
        dist[i]=0;
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int j=0;j<g[v].size();++j){
                int nv=g[v][j];
                if(dist[nv]!=-1)continue;
                dist[nv]=dist[v]+1;
                q.push(nv);
            }
        }
        
        
        for(int j=0;j!=N;++j){
            ans[i][j]=dist[j];
        }
        /*for(int a=0;a!=N;++a){
            for(int b=0;b!=N;++b){
                cout<<ans[a][b]<<" ";
            }
            cout<<endl;
        }*/
       
    }
    
    int a[N];
    for(int i=0;i!=N;++i){
        a[i]=0;
    }
    
    for(int i=0;i!=N;++i){
        for(int j=i+1;j!=N;++j){
            ++a[ans[i][j]];
        }
    }
    
    for(int i=1;i!=N;++i){
        cout<<a[i]<<endl;
    }
    
    
}
