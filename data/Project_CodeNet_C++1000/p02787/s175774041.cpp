// ABC153-E
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define e_b emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll h,n;
    cin>>h>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    ll inf=pow(10,18);
    vector<ll> dp(h+100,inf);
    dp[0]=0;
    rep(i,n){ //使う魔法
        rep(j,h){ //スタート地点
            ll next=min(h,j+a[i]);
            if(dp[j]!=inf) dp[next]=min(dp[next],dp[j]+b[i]);
        }
    }
    cout<<dp[h]<<endl;
    return 0;
}