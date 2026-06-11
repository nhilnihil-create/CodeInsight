#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000
#define MAX_V 10

int d[MAX_V][MAX_V]; // d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF.ただしd[i][i]=0とする)
int V; // 頂点数

void warshall_floyd() {
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void clearD() {
    for(int i=0;i<MAX_V;i++) {
        for(int j=0;j<MAX_V;j++) {
            if(i==j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }
}

main() {

    int n,a, b, c;
    V = MAX_V;
    while(cin>>n,n!=0) {
        clearD();
        for(int i=0;i<n;i++) {
            cin>>a>>b>>c;
            d[a][b]=c;
            d[b][a]=c;
        }
        warshall_floyd();
        int ans = INF;
        int ans_pos = 0;
        for(int i=0;i<V;i++) {
            int sum = 0;
            for(int j=0;j<V;j++) {
                if(d[i][j] == INF) continue;
                sum += d[i][j];
            }
            if(sum != 0 && sum < ans) {
                ans = sum;
                ans_pos = i;
            }
        }
        cout << ans_pos << " " << ans << endl;
    }
}