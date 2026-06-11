#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int g[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, k, v;
    int i, j;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>u>>k;
        for(j=0; j<k; j++) {
            cin>>v;
            g[u-1][v-1]=1;
        }
    }
    for(i=0; i<n; i++) {
        cout<<g[i][0];
        for(j=1; j<n; j++) {
            cout<<' '<<g[i][j];
        }
        cout<<'\n';
    }
    return 0;
}