#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<62;

int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &t : a) cin>>t;
    for(auto &t : b) cin>>t;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;++i)q.push({b[i],i});
    ll ret = 0ll;
    while(!q.empty()){
        auto cur = q.top();q.pop();
        int val = cur.first;
        int index = cur.second;
        int bef = (index-1+n)%n;
        int nex = (index+1)%n;
        if(val < a[index])break;
        if(val == a[index])continue;
        if(b[bef] + b[nex] == 0)break;
        int num = (val - a[index])/(b[bef]+b[nex]);
        val -= num*(b[bef]+b[nex]);
        if(num)q.push({val,index});
        b[index] = val;
        ret+=num;
    }
    for(int i=0;i<n;++i)if(a[i] != b[i])ret = -1;
    cout << ret << endl;
    return 0;
}

