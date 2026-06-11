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

int main(){
    lli n,k,a,ans=0,b=0;
    lli i,j;
    vector<lli> vec;
    cin>>n>>k;
    rep(i,0,n){
        cin>>a;
        vec.push_back(a);
    }
    rep(i,0,n-1){
        rep(j,i+1,n){
            if(vec[i]>vec[j]){
                ans++;
                ans%=N;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            if(vec[i]>vec[j]){
                b++;
            }
        }
    }
//    cout<<ans<<" "<<b<<endl;
    ans*=k;
    ans%=N;
    k=(((k-1)*k)/2)%N;
//    cout<<b*(k/2)<<endl;
    ans+=((b*k)%N);
    ans%=N;
    cout<<ans<<endl;
}
