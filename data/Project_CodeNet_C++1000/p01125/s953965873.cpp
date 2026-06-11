#include<iostream>
using namespace std;
  
int main(){
    int N,M,t[21][21],l,a,b,i,j,flg=0;
    int x,y;
    char d;
    for(;;){
        x=10;y=10;
        flg=0;
        cin>>N;
        if(N==0){break;}
        for(i=0;i<=20;i++){
            for(j=0;j<=20;j++){
                t[i][j]=0;
            }
        }
        for(i=0;i<N;i++){
            cin>>a>>b;
            t[a][b]=1;
        }
        cin>>M;
        for(i=0;i<M;i++){
            cin>>d>>l;
            switch(d){
            case 'N':
                for(j=0;j<l;j++){
                    y++;
                    t[x][y]=0;
                }
                break;
            case 'E':
                for(j=0;j<l;j++){
                    x++;
                    t[x][y]=0;
                }
                break;
            case 'S':
                for(j=0;j<l;j++){
                    y--;
                    t[x][y]=0;
                }
                break;
            case 'W':
                for(j=0;j<l;j++){
                    x--;
                    t[x][y]=0;
                }
                break;
            default:
                break;
  
  
            }
        }
        for(i=0;i<21;i++){
            for(j=0;j<21;j++){
                if(t[i][j]==1){
                    flg=1;
                }
            }
        }
        if(flg==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}