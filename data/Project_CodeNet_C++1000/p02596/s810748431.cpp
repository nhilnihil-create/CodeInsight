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
    lli k,a=0;
    map<lli,lli> mp;
    lli i=1;
    cin>>k;
    if(k%2==0){
        i=-1;
    }
    else{
        while(1){
            a=a*10+7;
            a%=k;
            mp[a]++;
            if(a==0){
                break;
            }
            if(mp[a]==2){
                i=-1;
                break;
            }
            i++;
        }
    }
    cout<<i<<endl;
}
