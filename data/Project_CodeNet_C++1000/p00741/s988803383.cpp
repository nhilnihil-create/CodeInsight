#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define PB_VEC(Itr1,Itr2) (Itr1).insert((Itr1).end(),(Itr2).begin(),(Itr2).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;

vector< vector<int> > M;
int h,w;

bool dfs(int y, int x){
    if(y>=h||y<0||x>=w||x<0)return false;
    if(M[y][x]==0)return false;
    M[y][x]=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            dfs(y+i,x+j);
        }
    }
    return true;
}

int ans(){
    int res=0;
    REP(i,h)REP(j,w){
        if(dfs(i,j))res++;
    }
    
    return res;
}

int main(){
    
    while(true){
        cin>>w>>h;
        if(h==0&&w==0)break;
        
        M.clear();
        M.resize(h);
        REP(i,h){
            REP(j,w){
                int t; cin>>t;
                M[i].push_back(t);
            }
        }
        
        cout<<ans()<<endl;
        
    }
    
    return 0;
}