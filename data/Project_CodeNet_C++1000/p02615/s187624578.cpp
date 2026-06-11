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
    lli n,a,sum=0,low=N;
    vector<lli> vec;
    lli i,j,k;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end(),greater<lli>());
    rep(i,0,n-1){
        if(i==0){
            sum+=vec[i];
//            cout<<vec[i]<<"を加える"<<endl;
        }
        else{
            sum+=vec[(i+1)/2];
//            cout<<vec[(i+1)/2]<<"を加える"<<endl;
        }
    }
    cout<<sum<<endl;
}
