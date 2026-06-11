#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string field[2160];
int l[2160][2160];
int r[2160][2160];
int d[2160][2160];
int u[2160][2160];

int  main(){
    int h, w;
    cin >> h >> w;
    for (int i= 0 ;i<h; i ++){
        cin >> field[i];
    }
    for(int i = 0;i < h; i ++){
        for(int j= 0;j < w; j++){
            if(field[i][j] == '#'){
                l[i][j] = 0;
                u[i][j] = 0;
            }
            else{
                u[i][j] = (i==0)?1:u[i-1][j] + 1;
                l[i][j] = (j==0)?1:l[i][j-1] + 1;
            }
        }
    }
    for(int i = h-1;i >=0; i --){
        for(int j= w-1;j >= 0 ; j--){
            if(field[i][j] == '#'){
                r[i][j] = 0;
                d[i][j] = 0;
            }
            else{
                d[i][j] = (i==h-1)?1:d[i+1][j] + 1;
                r[i][j] = (j==w-1)?1:r[i][j+1] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0;i < h ;i++){
        for(int j = 0; j < w; j++){
            if(field[i][j] == '#')continue;
            res = max(res, r[i][j]+ l[i][j]+d[i][j]+ u[i][j]-3);
        }
    }
    cout << res << endl;

    return 0;

}