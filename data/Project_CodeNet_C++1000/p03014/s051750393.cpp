#include<iostream>
#include<vector>
#include<string>
using namespace std;

int H,W;
string maze[2005];
vector<vector<int>> Up;
vector<vector<int>> Right;
vector<vector<int>> Down;
vector<vector<int>> Left;

void R(){
    for(int i=0;i<H;++i){
        int cur=0;
        for(int j=0;j<W;++j){
            if(maze[i][j]=='#') cur=0;
            else Right[i][j]=++cur;
        }
    }
}

void L(){
    for(int i=0;i<H;++i){
        int cur=0;
        for(int j=W-1;j>=0;--j){
            if(maze[i][j]=='#') cur=0;
            else Left[i][j]=++cur;
        }
    }
}

void D(){
    for(int j=0;j<W;++j){
        int cur=0;
        for(int i=0;i<H;++i){
            if(maze[i][j]=='#') cur=0;
            else Down[i][j]=++cur;
        }
    }
}

void U(){
    for(int j=0;j<W;++j){
        int cur=0;
        for(int i=H-1;i>=0;--i){
            if(maze[i][j]=='#') cur=0;
            else Up[i][j]=++cur;
        }
    }
}

int main(){
    cin>>H>>W;
    Up.assign(H,vector<int>(W,0));
    Down.assign(H,vector<int>(W,0));
    Right.assign(H,vector<int>(W,0));
    Left.assign(H,vector<int>(W,0));
    for(int i=0;i<H;++i) cin>>maze[i];

    U(); D(); R(); L();
    int ans=0;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            int t=Up[i][j]+Right[i][j]+Down[i][j]+Left[i][j]-3;
            ans=ans<t?t:ans;
        }
    }

    cout<<ans<<endl;
}