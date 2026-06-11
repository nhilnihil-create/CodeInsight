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
    lli n,sum=0;
    lli i,j,k;
    map<lli,lli> mp;
    cin>>n;
//    if(n==1){
//        cout<<"0"<<endl;
//        exit(0);
//    }
    i=2;
    while((i*i)<=n){
        if(n%i==0){
            n/=i;
//            cout<<i<<"で割って"<<n<<"になる"<<endl;
            mp[i]++;
        }
        else{
            i++;
        }
    }
    if(n>1){
        mp[n]++;
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        i=1;
        while(1){
            if((1+i)*i/2>itr->second){
                sum+=i-1;
                break;
            }
            else{
                i++;
            }
        }
    }
    cout<<sum<<endl;
}
