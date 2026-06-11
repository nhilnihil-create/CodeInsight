#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i,j,k;
    int bg[3][3];
    int ans[3][3]={0};
    rep(i,3){
        rep(j,3){
            cin>>bg[i][j];
        }
    }
    int N;
    cin>>N;
    int b[N];
    rep(i,N){
        cin>>b[i];
    }
    rep(i,N){
        rep(j,3){
            rep(k,3){
                if(b[i]==bg[j][k]){
                    ans[j][k]=1;
                }
            }
        }
    }
    //横
    rep(i,3){
        int sum=0;
        rep(j,3){
            if(ans[i][j]==1)
                sum++;
        }
        if(sum==3){
            cout<<"Yes";
            return 0;
        }
    }
    rep(i,3){
        int sum=0;
        rep(j,3){
            if(ans[j][i]==1)
                sum++;
        }
        if(sum==3){
            cout<<"Yes";
            return 0;
        }
    }
    if((ans[0][0]+ans[1][1]+ans[2][2])==3){
        cout<<"Yes";
    }else if((ans[0][2]+ans[1][1]+ans[2][0])==3){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}
