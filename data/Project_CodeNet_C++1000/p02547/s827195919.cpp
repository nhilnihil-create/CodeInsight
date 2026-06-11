#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define INF 1e9

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
}

int main()
{
    init();
    int n;
    cin>>n;
    int d1, d2;
    int c=0,tmp=0;
    rep(i,n){
        cin>>d1>>d2;
        if(d1==d2)c++;
        if(d1!=d2)c=0;
        if(c>=3)tmp=1;
    }
    if(tmp==1){
        Yes;
    }else{
        No;
    }
}
