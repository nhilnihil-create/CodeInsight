#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

//lli gcd(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    if(x%y==0){
//        return y;
//    }
//    else{
//        return gcd(y,x%y);
//    }
//}
//
//lli lcm(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    return x*y/gcd(x,y);
//}

struct work{
    lli w;
    lli t;
    bool operator<(const work &another)const{
        return t<another.t;
    }
};

int main(){
    lli a,n,b[3];
    string ans="Yes";
    map<lli,lli> map;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        map[a]++;
    }
    switch(map.size()){
        case 1:
            if(map[0]!=n){
                ans="No";
            }
            break;
        case 2:
            if(n%3!=0){
                ans="No";
            }
            else{
                if(map[0]!=n/3){
                    ans="No";
                }
            }
            break;
        case 3:
            if(n%3!=0){
                ans="No";
            }
            else{
                j=0;
                for(auto itr=map.begin();itr!=map.end();itr++){
                    b[j]=itr->first;
                    if(itr->second!=n/3){
                        ans="No";
                    }
                    j++;
                }
                b[1]^=b[2];
                if(b[0]!=b[1]){
                    ans="No";
                }
            }
            break;
        default:ans="No";break;
    }
    cout<<ans<<endl;
}
