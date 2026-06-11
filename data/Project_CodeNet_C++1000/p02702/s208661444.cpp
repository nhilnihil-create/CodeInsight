#include<iostream>
#include<numeric>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<tuple>
#include<string>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    ll ans=0,x=1,sum=0;
    map<ll,int> m;
    for(ll i=0;i<(ll)s.size();i++){
        sum+=(s[i]-'0')*x;
        sum%=2019;
        m[sum]++;
        x=x*10%2019;
    }
    m[0]++;
    for(auto p : m){
        ans+=p.second*(p.second-1)/2;
    }
    cout<<ans<<endl;
}