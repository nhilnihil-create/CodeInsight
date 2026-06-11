#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)n;i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
#define BIT_FLAG_1 (1<<1) // 0000 0000 0000 0010
#define BIT_FLAG_2 (1<<2) // 0000 0000 0000 0100
#define BIT_FLAG_3 (1<<3) // 0000 0000 0000 1000
#define BIT_FLAG_4 (1<<4) // 0000 0000 0001 0000
#define BIT_FLAG_5 (1<<5) // 0000 0000 0010 0000
#define BIT_FLAG_6 (1<<6) // 0000 0000 0100 0000
#define BIT_FLAG_7 (1<<7) // 0000 0000 1000 0000

int main(){
    int n,m;
    int h[100001],aa[100001];
    cin >> n >> m;

    rep(i,n){
        cin >> h[i];
        aa[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        aa[a]=max(aa[a],h[b]);
        aa[b]=max(aa[b],h[a]);
    }
    int ans=0;
    rep(i,n)
        ans+=h[i]>aa[i];
    cout << ans << endl;
}