#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++){
        cin>>S[i];
    }
    vector<vector<int> > L(H,vector<int>(W,0));
    vector<vector<int> > R(H,vector<int>(W,0));
    vector<vector<int> > U(H,vector<int>(W,0));
    vector<vector<int> > D(H,vector<int>(W,0));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#') L[i][j]=-1;
          else if(j==0) L[i][j]=0;
            else L[i][j]=L[i][j-1]+1;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=W-1;j>=0;j--){
          if(S[i][j]=='#') R[i][j]=-1;
          else if(j==W-1) R[i][j]=0;
            else R[i][j]=R[i][j+1]+1;
        }
    }
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
          if(S[i][j]=='#') U[i][j]=-1;
          else if(i==0) U[i][j]=0;
            else U[i][j]=U[i-1][j]+1;
        }
    }
    for(int j=0;j<W;j++){
        for(int i=H-1;i>=0;i--){
          if(S[i][j]=='#') D[i][j]=-1;
          else if(i==H-1) D[i][j]=0;
            else D[i][j]=D[i+1][j]+1;
        }
    }
    int m=-1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)if(S[i][j]!='#'){
            m=max(m,L[i][j]+R[i][j]+U[i][j]+D[i][j]+1);
        }
    }
    cout<<m<<endl;
    return 0;
}