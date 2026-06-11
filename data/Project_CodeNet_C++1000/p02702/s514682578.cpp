#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#define For(i,x,y) for(register int i=(x); i<=(y); i++)
using namespace std;
typedef long long ll;
vector<ll>v(2019);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    v[0]=1;
    int len=s.size();
    ll ans=0;
    int cnt=1,temp=0;
    reverse(s.begin(),s.end());
    For(i,0,len-1)
    {
        temp=(temp+(s[i]-'0')*cnt)%2019;
        ans+=v[temp];
        v[temp]++;
        cnt=cnt*10%2019;//模的运算法则（乘法原理）
    }
    cout<<ans<<endl;
}
