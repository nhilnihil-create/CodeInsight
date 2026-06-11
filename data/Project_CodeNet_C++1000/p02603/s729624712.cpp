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

struct trader{
    
    vector<lli> vec;
    
    trader(lli n){
        lli i,a;
        rep(i,0,n){
            cin>>a;
            vec.push_back(a);
        }
    }
    
    lli trading(lli p){
        lli i,t=0;
        string s="down";
        rep(i,0,vec.size()){
            if(i!=vec.size()-1){
                if(s=="down"&&vec[i]<vec[i+1]){
                    t=p/vec[i];
                    p%=vec[i];
//                    cout<<"株を"<<t<<"枚購入し、残金は"<<p<<"円"<<endl;
                    s="up";
                }
                else if(s=="up"&&vec[i]>vec[i+1]){
                    p+=t*vec[i];
//                    cout<<"株を"<<t<<"枚売却し、残金は"<<p<<"円"<<endl;
                    s="down";
                }
            }
            else{
                if(s=="up"){
                    p+=t*vec[i];
//                    cout<<"株を"<<t<<"枚売却し、残金は"<<p<<"円"<<endl;
                }
            }
        }
        return p;
    }
    
};

int main(){
    lli n,ans,p=1000;
    lli i,j;
    cin>>n;
    trader trade(n);
    ans=trade.trading(p);
    cout<<ans<<endl;
}
