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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    string s;
    cin>>s;
    if(s=="SUN"){
        cout<<7<<endl;
    }
    if(s=="MON"){
        cout<<6<<endl;
    }
    if(s=="TUE"){
        cout<<5<<endl;
    }
    if(s=="WED"){
        cout<<4<<endl;
    }
    if(s=="THU"){
        cout<<3<<endl;
    }
    if(s=="FRI"){
        cout<<2<<endl;
    }
    if(s=="SAT"){
        cout<<1<<endl;
    }
}