#include <bits/stdc++.h>
using namespace std;

long long x[55];
long long y[55];

bool AdjMat[55][55];
bool visited[55];

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%lld%lld", &x[i], &y[i]);
    }

    int minAns = N;
    for(int i = 0; i < N; i ++){
        for(int j = i+1; j < N; j ++){
            long long P = x[i]-x[j];
            long long Q = y[i]-y[j];

            memset(AdjMat, 0, sizeof(AdjMat));
            memset(visited, 0, sizeof(visited));

            for(int a = 0; a < N; a ++){
                for(int b = 0; b < N; b ++){
                    if( x[a]-x[b] == P && y[a]-y[b] == Q ){
                        AdjMat[a][b] = 1;
                        AdjMat[b][a] = 1;
                    }
                }
            }

            int tempAns = 0;

            for(int s = 0; s < N; s ++){
                if(visited[s]){continue;}
                queue<int> q;
                q.push(s);
                visited[s] = true;
                tempAns ++;
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    for(int v = 0; v < N; v ++){
                        if(AdjMat[u][v] && !visited[v]){
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            minAns = min(minAns, tempAns);
        }
    }

    printf("%d", minAns);
    return 0;
}
