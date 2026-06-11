#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int grid[501][501];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int cnt=1;cnt<=30;cnt++){
            if(pow(2,cnt-1)+i>n) break;
            int now=pow(2,cnt);
            for(int j=i+pow(2,cnt-1);j<=n;j+=now)
                grid[i][j]=cnt;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
//2 3 4 5 6 7 8 9