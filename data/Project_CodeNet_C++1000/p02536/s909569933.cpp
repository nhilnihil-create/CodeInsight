//https://atcoder.jp/contests/abl/tasks/abl_c
//查并集
#include <bits/stdc++.h>

using namespace std;

const int MAXM=1e5+4;
int f[MAXM];

int find(int x) {
    if (x==f[x]) {
        return x;
    } else {
        f[x]=find(f[x]);
        return f[x];
    }
}

int main() {
    int now=0;
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        f[i]=i;
    }
    
    for (int i=1; i<=m; i++) {
        int a,b;
        cin>>a>>b;
        
        a=find(a);
        b=find(b);

        if (a==b) {
            continue;
        }

        f[b]=a;
        now++;
    }

    cout<<n-1-now<<"\n";
    
    return 0;
}