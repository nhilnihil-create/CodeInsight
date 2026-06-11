#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin>>N;
    int a[N][N];
    rep(i,N)rep(j,N)a[i][j]=-1;
    rep(i,N){
        int A;
        cin>>A;
        rep(j,A){
            int x,y;
            cin>>x>>y;
            a[i][x-1]=y;
        }
    }
    int ans=0;
    for(int bit=0; bit<(1<<N); ++bit){
        int flag=1;
        int cnt=0;
        rep(i,N){
            if(bit&(1<<i)){
                rep(j,N){
                    if(a[i][j]!=-1){
                        if(a[i][j]==1){
                            if(!(bit&(1<<j))){
                                flag=0;
                                break;
                            }    
                        }
                        if(a[i][j]==0){
                            if(bit&(1<<j)){
                                flag=0;
                                break;
                            }
                        }
                    }
                }
            }
            if(flag==0)break;
        }
        if(flag==1)cnt=__builtin_popcount(bit);
        if(flag==1&&cnt>ans)ans=cnt;
    }
    cout<<ans<<endl;
    return 0;
}