#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int mo2 = 998244353;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
string str;
int main(){
    int n;
    cin>>n;
    vector<int> A(n),B(n);
    for(auto && a : A) cin>>a;
    for(auto && b : B) cin>>b;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;++i)q.push({B[i],i});
    ll ret = 0ll;
    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        int i=cur.second;
        if(B[i] < A[i]) break;
        if(A[i] == B[i]) continue;
        int l = (i+n-1)%n,r = (i+1)%n;
        int sum = B[l] + B[r];
        if(!sum) break;
        int num = (B[i] - A[i])/sum;
        ret += num;
        B[i] -= sum*num;
        if(num){
            q.push({B[i],i});
        }
    }
    
    for(int i=0;i<n;++i){
        if(A[i] != B[i])ret = -1;
    }
    cout << ret << endl;
    return 0;
}

