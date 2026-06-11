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

struct handv{
    
    lli sum;
    vector<string> vec;
    
    handv(lli h,lli w){
        lli i,d=0;
        string s;
        rep(i,0,h){
            cin>>s;
            d+=count(s.begin(),s.end(),'#');
            vec.push_back(s);
        }
        sum=d;
    }
    
    
    vector<lli> totwo(lli a,lli b){
        vector<lli> two;
        lli i;
        rep(i,0,a){
            two.push_back(b%2);
            b/=2;
        }
        return two;
    }
    
    lli answer(vector<lli> hig,vector<lli> wid){
        lli cnt=sum,i,j;
        rep(i,0,hig.size()){
            rep(j,0,wid.size()){
                if((hig[i]==1 || wid[j]==1)&&(vec[i][j]=='#')){
                    cnt--;
                }
            }
        }
        return cnt;
    }
    
    lli analysis(lli h,lli w,lli k){
        lli i,j,ans=0;
        vector<lli> hight,width;
        rep(i,0,pow(2.0,h)){
            rep(j,0,pow(2.0,w)){
                hight=totwo(h,i);
                width=totwo(w,j);
                if(k==answer(hight,width)){
                    ans++;
                }
            }
        }
        return ans;
    }
    
};

int main(){
    lli h,w,k,ans;
    lli i,j;
    cin>>h>>w>>k;
    handv hav(h,w);
    ans=hav.analysis(h,w,k);
    cout<<ans<<endl;
}
