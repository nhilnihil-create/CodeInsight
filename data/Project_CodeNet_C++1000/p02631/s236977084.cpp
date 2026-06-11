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

int main(){
    lli n,a,b=0,c;
    vector<lli> vec;
    lli i;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        b^=a;
        vec.push_back(a);
    }
    rep(i,0,n){
        c=vec[i]^b;
        cout<<c;
        if(i!=n-1){
            cout<<" ";
        }
    }
    cout<<endl;
}
