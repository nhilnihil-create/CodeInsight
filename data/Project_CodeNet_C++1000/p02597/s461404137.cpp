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
    lli n,a,b=0;
    string s;
    lli i,j;
    cin>>n>>s;
    a=count(s.begin(),s.end(),'R');
    rep(i,0,a){
        if(s[i]=='R'){
            b++;
        }
    }
    cout<<a-b<<endl;
}
