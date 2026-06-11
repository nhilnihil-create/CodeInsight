#include <iostream>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
#define ll long long
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define PI 3.14159265358979323

using namespace std;



int main() {

    fio;
    int TC=1;
    //cin>>TC;
    while(TC--){
        int h,w,k,cnt=0,ans=0;
        cin>>h>>w>>k;
        char mat[h][w],cur[h][w];

        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++) cin>>mat[i][j];

        for(int i=0;i<(1<<h);i++){
            for(int j=0;j<(1<<w);j++){
                cnt=0;

                for(int ci=0;ci<h;ci++)
                    for(int cj=0;cj<w;cj++) cur[ci][cj]=mat[ci][cj];

                for(int ii=0;ii<h;ii++)
                    if(1&(i>>ii)) for(int k=0;k<w;k++) cur[ii][k]='.';
                
                for(int ii=0;ii<w;ii++)
                    if(1&(j>>ii)) for(int k=0;k<h;k++) cur[k][ii]='.';

                for(int ci=0;ci<h;ci++)
                    for(int cj=0;cj<w;cj++) 
                        if(cur[ci][cj]=='#') cnt++;

                if(cnt==k) ans++;

            }
        }
        cout<<ans<<"\n";
    }
return 0;
}