#include "stdio.h"
#include <vector>
using namespace std;

vector<int> gra[100010];
int v[100020];

int DFS(int s) {
       v[s] = 1;
       for (int i = 0; i < gra[s].size(); i++) {
              if (v[gra[s][i]] == 0)
                 DFS(gra[s][i]);
       }
       return 0;
}

int main() {
       int N, M;
       scanf("%d%d", &N, &M);
       for (int i = 1; i <= N; i++) {
           v[i] = 0;
       }
       int v1, v2;
       for (int i = 0; i < M; i++) {
                scanf("%d%d", &v1, &v2);
                gra[v1].push_back(v2);
                gra[v2].push_back(v1);
       }
       int res = 0;
       for (int i = 1; i <= N; i++)
               if (v[i] == 0) {
                     DFS(i);
                     res++;
                }  
       printf("%d", res - 1); 
}