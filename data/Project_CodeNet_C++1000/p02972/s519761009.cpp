#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n),b(n);
    rep(i,0,n) cin>>a[i];
    int cnt = 0;
    repp(i,n-1,0){
        int num = 0;
        for (int j=(i+1)*2;j<n+1;j+=i+1){
            if (b[j-1]==1) num++;
        }
        if (num%2==1){
            if (a[i]==0) b[i] = 1,cnt++;
        }else{
            if (a[i]==1) b[i] = 1,cnt++;;
        }
    }
    cout<<cnt<<endl;
    rep(i,0,n){
        if (b[i]==1) cout<<i+1<<endl;
    }
}