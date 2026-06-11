#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,k;
    cin>>n>>k;
    int x=(n-1)*(n-2)/2;
    if(k>(n-1)*(n-2)/2){cout<<-1<<endl; return 0;}
    vector<P>a;
    for(int i=2; i<=n; ++i)a.push_back(P(1,i));
    for(int i=2; i<=n; ++i)for(int j=i+1; j<=n; ++j){
        if(x==k)break;
        a.push_back(P(i,j));
        x--;
    }
    cout<<a.size()<<endl;
    rep(i,a.size())cout<<a[i].first<<" "<<a[i].second<<endl;
}