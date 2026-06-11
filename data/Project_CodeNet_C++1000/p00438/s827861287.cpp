#include <bits/stdc++.h>
using namespace std;
bool tizu[20][20];
int a,b,c,kazu;
int tansa(int y,int x){
    if(y>b-1||x>a-1){return 0;}
    if(tizu[y][x]==1){return 0;}
    if(y==b-1&&x==a-1){kazu++;return 1;}
    tansa(y+1,x);tansa(y,x+1);
}
int main(){
    while(1){
        for(int i=0;i<20;i++){ 
            for(int j=0;j<20;j++){ tizu[i][j]=0; } 
        }
        kazu=0;
        cin>>a>>b;
        if(a+b==0)break;
        cin>>c;
        for(int i=0;i<c;i++){
            int x,y;
            cin>>x>>y;
            tizu[y-1][x-1]=1;
        }
        tansa(0,0);
        cout<<kazu<<endl;
    }
}