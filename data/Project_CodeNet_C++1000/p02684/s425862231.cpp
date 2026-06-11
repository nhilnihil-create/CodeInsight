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
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main() {
    lli n,k,a,roop,sta=N,now=0;
    vector<lli> vec,tel,check;
    lli i,j;
    cin>>n>>k;
    rep(i,0,n){
        cin>>a;
        vec.push_back(a);
        check.push_back(0);
    }
    tel.push_back(1);
    rep(i,0,n){
        if(check[vec[now]-1]==0){
//            cout<<i+1<<"回の移動で"<<vec[now]<<"に移動する"<<endl;
            check[vec[now]-1]=i+1;
            tel.push_back(vec[now]);
            now=vec[now]-1;
        }
        else{
            roop=i+1-check[vec[now]-1];
            sta=check[vec[now]-1];
//            cout<<roop<<" "<<sta<<endl;
            break;
        }
    }
    if(k<sta){
        cout<<tel[k]<<endl;
    }
    else{
        cout<<tel[sta+((k-sta)%roop)]<<endl;
    }
    
}
