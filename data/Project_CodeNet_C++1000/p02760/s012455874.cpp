#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main(){
    int A[3][3];
    rep(i, 3)rep(j, 3) cin>>A[i][j];
    int n;
    cin >> n;
    int B;
    int ok[3][3]={0};
    rep(i, n){
        cin >> B;
        rep(j, 3)rep(k, 3){
            if(A[j][k]==B) ok[j][k]=1;
        }
    }
 
    bool ans=false;
    if(ok[0][0]==1 && ok[0][1]==1 && ok[0][2]) ans=true;
    if(ok[1][0]==1 && ok[1][1]==1 && ok[1][2]) ans=true;
    if(ok[2][0]==1 && ok[2][1]==1 && ok[2][2]) ans=true;
    if(ok[0][0]==1 && ok[1][0]==1 && ok[2][0]) ans=true;
    if(ok[0][1]==1 && ok[1][1]==1 && ok[2][1]) ans=true;
    if(ok[0][2]==1 && ok[1][2]==1 && ok[2][2]) ans=true;
    if(ok[0][0]==1 && ok[1][1]==1 && ok[2][2]) ans=true;
    if(ok[2][0]==1 && ok[1][1]==1 && ok[0][2]) ans=true;
 
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}