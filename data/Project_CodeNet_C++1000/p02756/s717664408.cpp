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
    string s,r,l;
    cin>>s;
    int q;
    cin>>q;
    bool flag=true;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            flag=(!flag);
        }else{
            int f; char c;
            cin>>f>>c;
            if((flag==true && f==1) || (flag==false && f==2)){
                l+=c;
            }else{
                r+=c;
            }
        }        
    }
    if(flag){
        reverse(l.begin(), l.end());
        s=l+s+r;
    }else{
        reverse(s.begin(), s.end());
        reverse(r.begin(), r.end());
        s=r+s+l;
    }
    cout<<s<<endl;
}