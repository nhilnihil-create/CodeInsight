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


int main(){
int n;cin>>n;
vector<vector<pp>>a(16,vector<pp>(16));
pp x;
vi A(n);
int aw=0;
rep(i,n){
    
    cin>>A.at(i);
    rep(j,A.at(i)){
        int f,s;
        cin>>f>>s;
        a.at(i).at(j)=make_pair(f,s);

    }
}
    bitset<16> bs;

for(int bits=1;bits<(1<<n);bits++){
    int flag=0;
    int ans=0;
    rep(i,n){
        if((1<<i)&bits){
        rep(j,A.at(i)){
            
            if(a.at(i).at(j).se==1){
            if(bits&(1<<(a.at(i).at(j).fi-1))){
                        //ans++;
            }else{flag=1; break;
            }
            }else{
                if(bits&(1<<(a.at(i).at(j).fi-1))){
                    flag=1;break;
                }
            }
            //ans++;
            
            //ans++;
        }
        }
if(flag)break;
if(i==n-1){
bs=bits;

if(aw<bs.count())aw=bs.count();
    }

}
    }
    //ans++;
    //bitset<16> bs=bits;
   /* if(bs.count()==ans){
        if(aw<ans)aw=ans;
    }*/

cout<<aw<<endl;

}