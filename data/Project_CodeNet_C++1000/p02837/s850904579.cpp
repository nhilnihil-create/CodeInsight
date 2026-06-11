#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <iostream>
#include <bitset>

#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) begin(c),end(c)
#define pp pair<int,int>
using namespace std;

vv(a,15,15);

int main(){
int n;cin>>n;
rep(i,n)rep(j,n) a.at(i).at(j) = -1;
//vector<vector<pp>>a(16,vector<pp>(16));
//pp x;
//vi A(n);
//int aw=0;
rep(i,n){
    int m;
    cin>>m;
    rep(j,m){
        int f,s;
        cin>>f>>s;
        //a.at(i).at(j)=make_pair(f,s);
        --f;
        a.at(i).at(f)=s;
    }
}
    //bitset<16> bs;
   int ans=0;
for(int bits=0;bits<(1<<n);bits++){
    //int flag=0;
    //int ans=0;
    vi d(n);
rep(j,n)if(bits>>j&1)d.at(j)=1;
    bool ok=true;
    rep(i,n){
        if(d.at(i)){
            rep(j,n){
                if(a.at(i).at(j)==-1)continue;
                if(a.at(i).at(j)!=d.at(j))ok=false;
            }


        }
    }
    if(ok)ans=max(ans,__builtin_popcount(bits));
    }

    
    //ans++;
    //bitset<16> bs=bits;
   /* if(bs.count()==ans){
        if(aw<ans)aw=ans;
    }*/

cout<<ans<<endl;

}