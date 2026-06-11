#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 10;
int f[N][N];
char a[N][N];
void upd(int &x,int y){
    x = min(x,y);
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>(a[i]+1);
    memset(f,0x7f,sizeof(f));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(i==1&&j==1) f[i][j] = (a[1][1]=='#');
        if(a[i][j]=='#'){
            upd(f[i+1][j],f[i][j]);
            upd(f[i][j+1],f[i][j]);
        }
        else{
            upd(f[i+1][j],f[i][j]+(a[i+1][j]=='#'));
            upd(f[i][j+1],f[i][j]+(a[i][j+1]=='#'));
        }
    }
    cout<<f[n][m]<<endl;
}
