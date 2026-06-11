#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n+5);
    vector<int>dfs(n+5);
    int mn=1;
    int j=1;
    for(int i=n-1;i>=1&&m--;i--){
        while(v[j+i]) i--;
        while(dfs[n-(i)]||i==n-i) i--;
        cout<<j<<' '<<j+i<<'\n';
        dfs[i]=1;
        v[j]=v[j+i]=1;
        if(m==0)
            break;
        while(j<=n&&v[j]) j++;
    }
    return 0;
}
/***
32
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5

6
2 3 3 1 3 1
*/
