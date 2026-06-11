#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main(){
    int H,W;cin>>H>>W;
    vector<string>S(H);
    rep(i,H){
        cin>>S.at(i);
    }
    Graph L(H,vector<int>(W));
    Graph R(H,vector<int>(W));
    Graph U(H,vector<int>(W));
    Graph D(H,vector<int>(W));
    rep(i,H){
        rep(j,W){
            if(j==0){
                L[i][j]=0;
                if(S[i][j]=='.'){
                    L[i][j]=1;
                }
            }
            else{
                if(S[i][j]=='#'){
                    L[i][j]=0;
                }
                else{
                    L[i][j]=L[i][j-1]+1;
                }
            }
        }
    }
    rep(i,H){
        for(int j=W-1;j>=0;j--){
            if(j==W-1){
                R[i][j]=0;
                if(S[i][j]=='.'){
                    R[i][j]=1;
                }
            }
            else{
                if(S[i][j]=='#'){
                    R[i][j]=0;
                }
                else{
                    R[i][j]=R[i][j+1]+1;
                }
            }
        }
    }
    rep(i,W){
        rep(j,H){
            if(j==0){
                U[j][i]=0;
                if(S[j][i]=='.'){
                    U[j][i]=1;
                }
            }
            else{
                if(S[j][i]=='#'){
                    U[j][i]=0;
                }
                else{
                    U[j][i]=U[j-1][i]+1;
                }
            }
        }
    }
    rep(i,W){
        for(int j=H-1;j>=0;j--){
            if(j==H-1){
                D[j][i]=0;
                if(S[j][i]=='.'){
                    D[j][i]=1;
                }
            }
            else{
                if(S[j][i]=='#'){
                    D[j][i]=0;
                }
                else{
                    D[j][i]=D[j+1][i]+1;
                }
            }
        }
    }
    priority_queue<int>Ans;
    rep(i,H){
        rep(j,W){
            Ans.push(L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
        }
    }
    cout<<Ans.top()<<endl;
}