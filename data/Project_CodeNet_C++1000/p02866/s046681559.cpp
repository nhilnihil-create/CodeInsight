#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=(n)-1;i>j-1;i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli n,d,m=0,ans=1;
    vector<lli> vec;
    map<lli,lli> mp;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>d;
        vec.push_back(d);
        m=max(m,d);
        mp[d]++;
    }
    if(mp[0]!=1||vec[0]!=0){
        cout<<0<<endl;
    }
    else{
        rep(i,0,m+1){
            if(mp[i]!=0){
                if(i>1){
//                    cout<<"きてる？"<<endl;
                    rep(j,0,mp[i]){
                        ans*=mp[i-1];
                        ans%=M;
                    }
                }
            }
            else{
                cout<<0<<endl;
                exit(0);
            }
        }
        cout<<ans<<endl;
    }
}
