#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> fruit;
    rep(i,n){
        int v;
        cin>>v;
        fruit.push_back(v);
    }
    sort(fruit.begin(),fruit.end());
    int sum=0;
    rep(i,k){
        sum+=fruit[i];
    }
    cout<<sum<<endl;
}