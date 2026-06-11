//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int h,w;
char arr[105][105]; 
int memo[105][105];
int f(int x,int y){
    if(x==h && y==w){
        return arr[h][w]=='#';
    }
    if(memo[x][y]!=-1) return memo[x][y];
    int res=100000000;
    if(arr[x][y]=='.'){
        if(x<h){
            res=min(res,f(x+1,y));
        }
        if(y<w){
            res=min(res,f(x,y+1));
        }

    }
    else{
        if(x<h){
            res=min(res,f(x+1,y)+ ((arr[x+1][y]=='.') ? 1:0));
        }
        if(y<w){
            res=min(res,f(x,y+1)+ ((arr[x][y+1]=='.') ? 1:0));
        }
    }
    return memo[x][y]=res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>arr[i][j];
        }
    }
    memset(memo,-1,sizeof(memo));
    cout<<f(1,1)<<endl;
}