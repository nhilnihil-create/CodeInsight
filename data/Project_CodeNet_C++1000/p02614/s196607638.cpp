#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    int h,w,k;
    cin>>h>>w>>k;

    int maskh=(1<<h)-1;
    int maskw=(1<<w)-1;

    char arr[h][w];

    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<maskh;i++) {
        for(int j=0;j<maskw;j++) {
            int black=0;
            for(int x=0;x<h;x++) {
                for(int y=0;y<w;y++) {
                    if((((i>>x)&1)==0) && ((j>>y)&1)==0 && arr[x][y]=='#') {
                        black++;
                    }
                }
            }
            if(black==k) {
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}


