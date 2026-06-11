
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<int> visited(n+1,-1);
    rep(i,0,n)cin>>a[i];

    int i=1;
    vector<int> num;
    while(visited[i]==-1){
        visited[i]=num.size();
        num.push_back(i);
        i=a[i-1];
    }

    int cnt=num.size()-visited[i]; //周期 visited[i]:最後に訪れた町i
    int l=visited[i];
    if(k<l)cout<<num[k]<<endl;
    else{
        k-=l;
        k%=cnt;
        cout<<num[l+k]<<endl;
    }
    return 0;
}

