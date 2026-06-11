#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;

struct Dice{
  int num[6];
};

int main(){
    vector<int> number(6);
    Dice d1;
    for(int i=0; i<6; i++){
        cin>>d1.num[i];
    }
    cin.ignore();
    int a;
    cin>>a;
    int top[a]={0};
    int front[a]={0};
    int q1[a],q2[a];
    for(int i=0; i<a; i++){
        cin>>q1[i]>>q2[i];
        for(int j=0; j<6; j++){
            if(q1[i]==d1.num[j]) top[i]=j+1;
            if(q2[i]==d1.num[j]) front[i]=j+1;
        }
    }

    int r[3][4]={{1,2,6,5} , {1,3,6,4} , {2,3,5,4}};
    for(int i=0; i<a; i++){
        int dtop=1;
        int n=5,e=3,s=2,w=4;
        if(top[i]==3){
            w=dtop;
            dtop=e;
            e=7-w;
        }else if(top[i]==4){
            e=dtop;
            dtop=w;
            w=7-e;
        }else{
            for(int j=0;j<4; j++){
                if(r[0][j]==top[i]) break;
                n=dtop;
                dtop=s;
                s=7-n;
            }
        }

        int rnum=0;
        for(int j=0; j<3; j++){
            for(int k=0; k<4; k++){
                if(r[j][k]==top[i]) break;
                if(k==3) rnum=j;
            }
        }

        for(int j=0; j<4; j++){
            if(front[i]==s) break;
            int tmp=n;
            n=w;
            w=s;
            s=e;
            e=tmp;
        }

        cout<<d1.num[e-1]<<endl;

    }
    return 0;
}
