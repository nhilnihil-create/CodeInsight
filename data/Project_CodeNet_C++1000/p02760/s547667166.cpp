//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
//using
using namespace std;
/*using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;*/
//vector<vector<char> > hyou(N, vector<char>(N));
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int a=0,b=0,c=0;

signed main(){
    vector<vector<int> > A(3, vector<int>(3));
    vector<vector<bool> > aa(3, vector<bool>(3));
    rep(i,3)rep(j,3)cin>>A[i][j];
    cin>>a;
    vector<int>B(a);
    rep(i,a)cin>>B[i];
    rep(i,3){
        rep(j,3){
            aa[i][j]=false;
            rep(k,a){
                if(A[i][j]==B[k])aa[i][j]=true;}}}
    rep(i,3)if(aa[i][0]==true&&aa[i][1]==true&&aa[i][2]==true)b=1;
    rep(i,3)if(aa[0][i]==true&&aa[1][i]==true&&aa[2][i]==true)b=1;
    if(aa[0][0]==true&&aa[1][1]&&aa[2][2])b=1;
    if(aa[0][2]==true&&aa[1][1]&&aa[2][0])b=1;
    if(b==1)print("Yes") else print("No");
}
