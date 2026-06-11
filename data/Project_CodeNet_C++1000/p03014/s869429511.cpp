#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll H,W;
vector<string> S;


int drow[] = {-1,1};

bool onBoard(int row,int column){
    if(row>=0 && row<H && column>=0 && column<W){
        return true;
    }
    return false;
}

int UDP[2000][2000];
int DDP[2000][2000];
int DDfs(int row,int t){
    if(DDP[row][t] != -1){
        return DDP[row][t];
    }
    int retVal =1;
    int nt = t -1;
    if(onBoard(row,nt)){
        retVal += DDfs(row,nt);
    }
    DDP[row][t] = retVal;
    return retVal;
}
int UDfs(int row,int t){
    if(UDP[row][t] != -1){
        return UDP[row][t];
    }
    int retVal =1;
    int nt = t +1;
    if(onBoard(row,nt)){
        retVal += UDfs(row,nt);
    }
    UDP[row][t] = retVal;
    return retVal;
}
int LDP[2000][2000];
int RDP[2000][2000];
int LDfs(int t,int column){
    if(LDP[t][column] != -1){
        return LDP[t][column];
    }
    int retVal =1;
    int nt = t -1;
    if(onBoard(nt,column)){
        retVal += LDfs(nt,column);
    }
    LDP[t][column] = retVal;
    return retVal;
}
int RDfs(int t,int column){
    if(RDP[t][column] != -1){
        return RDP[t][column];
    }
    int retVal =1;
    int nt = t +1;
    if(onBoard(nt,column)){
        retVal += RDfs(nt,column);
    }
    RDP[t][column] = retVal;
    return retVal;
}

int main() {
    cin >> H >>W;
    S.resize(H);
    for(int i=0;i<H;i++){
        cin >> S[i];
    }
   
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == '#'){
                UDP[i][j] = 0;
                DDP[i][j] =0;
                LDP[i][j] = 0;
                RDP[i][j] =0;
            }else{
               UDP[i][j] = -1;
                DDP[i][j] =-1;
                LDP[i][j] = -1;
                RDP[i][j] =-1;
            }
        }
    }
    int ans =0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == '#'){
                continue;
            }
            ans = max(ans,UDfs(i,j)+ DDfs(i,j)+LDfs(i,j)+RDfs(i,j)-3);
            // cerr <<"i="<<i <<", j=" << j <<"val = "<<UDfs(i,j)+ DDfs(i,j)+LDfs(i,j)+RDfs(i,j)-3<<endl;
        }
    }
    cout << ans << endl;
    return 0;
}