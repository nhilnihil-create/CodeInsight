#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    bool ar[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        char x;cin>>x;
        ar[i][j]= x == '#';
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<m);j++){
            int cnt=0;
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    if(ar[x][y]&&(i&(1<<x))&&(j&(1<<y)))cnt++;
                }
            }
            if(cnt==k)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
} 