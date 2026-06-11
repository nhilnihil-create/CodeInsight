#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int g[102][102];
    int d[102];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            g[i][j] = 0;
        }
        d[i] = -1;
    }
    
    int u,k;
    for(int i=0; i<n; i++){
        cin>>u>>k;
        for(int j=0; j<k; j++){
            int v;
            cin>>v;
            g[u][v] = 1;
        }
    }

    int q[102];
    int h = 0, t = h + 1;
    q[h] = 1;
    d[ q[h] ] = 0;
    while(h != t){
        u = q[h++];
        for(int i=1; i<=n; i++){
            if(g[u][i] == 1 && d[i] == -1){
                g[u][i] = 0;
                d[i] = d[u]+1; 
                q[t++] = i;
              
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout<< i << " " << d[i] << endl;
    }
    
    return 0;
}