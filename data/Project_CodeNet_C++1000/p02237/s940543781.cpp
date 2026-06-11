#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int  n;
    cin>>n;
    int g[101][101];
    for (int i = 0; i < n;i++) {
        for (int j = 0; j<n;j++) {
            g[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            v--;
            g[u][v] = 1;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j) cout<<" ";
            cout<<g[i][j];
        }
        cout<<"\n";
    }
    return 0;
}