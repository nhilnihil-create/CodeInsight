#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=3e5+9;
int n,m,k,has,v[20];
char a[8][8],g[8][8];

void clean(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=g[i][j];
        }
    }
}

void c(int r,int c){
    if(c!=-1){
        for(int i=0;i<n;i++){
            if(a[i][c]=='#')a[i][c]='.';
        }
     }
     if(r!=-1) {
        for(int i=0;i<m;i++){
            if(a[r][i]=='#')a[r][i]='.';
        }
    }
}

bool ok(){
    int has=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#')has++;
        }
    }
    return has==k;
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int>>v;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int ans=0;
    int tot=n+m;
    for(int i=0;i<n;i++){
        v.push_back({0,i});
    }
    for(int i=0;i<m;i++){
        v.push_back({1,i});
    }
    for(int mask=0;mask<(1<<tot);mask++){
        clean();
        for(int i=0;i<tot;i++){
            if((mask>>i)&1){
                int rr=v[i].first;
                int who=v[i].second;
                if(rr==0){
                    c(who,-1);
                }
                else {
                    c(-1,who);
                }
            }
        }
        if(ok())ans++;
    }
    cout<<ans<<'\n';



    return 0;
}

