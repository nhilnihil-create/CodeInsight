#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll H,W;
ll A[101][101];
ll AA[101][101];
ll ans=0;
P C[101][101];
int kansus(int a,int b,int c,int d){
    if(A[a][b] == 1 && A[c][d] == 0)
    {
        return 1;
    }else{
        return 0;
    }
}
int main(){
    cin >> H >> W;
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            char a;
            cin >> a;
            if(a == '#'){
                A[i][j] = 1;
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i==0 && j == 0){
                continue;
            }else if(i==0){
                AA[i][j] = AA[i][j-1] + kansus(i,j,i,j-1);
            }else if(j==0){
                AA[i][j] = AA[i-1][j] + kansus(i,j,i-1,j);
            }else{
                AA[i][j] = min(AA[i-1][j]+kansus(i,j,i-1,j),AA[i][j-1]+kansus(i,j,i,j-1));
            }
        }
    }
    cout << AA[H-1][W-1] + A[0][0]<< endl;
    
}


