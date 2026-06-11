#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    vector<ll> num(n,-1);
    ll count=0; ////
    ll s=0;  
    ll roopStart=0;
    ll roop=0;  
    ll now=0;  ////
    while(true){
        if(num[now]>=0){
            s=num[now];
            roopStart=now;
            roop=count-num[now];
            break;
        }
        num[now]=count;
        count++;
        now=a[now];
    }
    if(k<s){
        now=0;
        while(k){
            now=a[now];
            k--;
        }
        cout<<now+1<<endl;
    }else{
        k-=s;
        k%=roop;
        now=roopStart;
        while(k){
            now=a[now];
            k--;
        }
        cout<<now+1<<endl;
    }

}