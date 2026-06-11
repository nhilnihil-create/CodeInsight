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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    ll a=t1*a1;
    ll b=t2*a2;
    ll c=t1*b1;
    ll d=t2*b2;
    ll ans;
    if(a+b>c+d){
        if(c>a){
            ans=2*((c-a)/(a+b-c-d))+1;
            if((c-a)%(a+b-c-d)==0) ans--;
            cout<<ans<<endl;
            return 0;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }else if(a+b<c+d){
        if(a>c){
            ans=2*((a-c)/(c+d-a-b))+1;
            if((a-c)%(c+d-a-b)==0) ans--;
            cout<<ans<<endl;
            return 0;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }else{
        cout<<"infinity"<<endl;
        return 0;
    }

}