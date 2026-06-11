#include<bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, X, Y;

int cnt[2005];

int main(){
    scanf("%d%d%d",&n,&X,&Y);

    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(i<=X&&j<=Y){
                ++cnt[min(j-i,X-i+Y-j+1)];
            }else if(i<=X&&j>Y){
                ++cnt[X-i+j-Y+1];
            }else if(i<=Y&&j<=Y){
                ++cnt[min(j-i,i-X+Y-j+1)];
            }else if(i<=Y&&j>Y){
                ++cnt[min(j-i,i-X+j-Y+1)];
            }else{
                ++cnt[j-i];
            }
        }
    }

    for(int i=1;i<n;++i){
        printf("%d\n",cnt[i]);
    }


    return 0;
}
