#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!

int grid[3][3];

void mark(int n){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]==n){
                grid[i][j]=0;
            }
        }
    }
}
bool rowB(int row){
    for(int col=0;col<3;col++){
        if(grid[row][col]!=0){
            return false;
        }
    }
    return true;
}
bool colB(int col){
    for(int row=0;row<3;row++){
        if(grid[row][col]!=0){
            return 0;
        }
    }
    return 1;
}
bool check(){
    for(int row=0;row<3;row++){
        if(rowB(row)){
            return 1;
        }
    }
    for(int col=0;col<3;col++){
        if(colB(col)){
            return 1;
        }
    }
    bool flag=1;
    // left diagonal
    for(int i=0;i<3;i++){
        if(grid[i][i]!=0){
            flag=0;break;
        }
    }
    if(flag){
        return 1;
    }
    
    // right diagonal
    flag=1;
    for(int i=0;i<3;i++){
        if(grid[i][3-1-i]!=0){
            flag=0;
            break;
        }
    }
    return flag;
}

void solve(){
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>grid[i][j];
        }
    }
    
    int n;
    cin>>n;
    
    while(n-->0){
       int x;
       cin>>x;
       mark(x);
    }
    if(check()){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}