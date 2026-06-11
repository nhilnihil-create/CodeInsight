#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll v[1<<18];
int main(){
    int n;
    cin>>n;
    int m=(1<<n);
    //st に入っているのはまだ生成していない生成したいスライム
    multiset<ll> st;
    rep(i,(1<<n)) cin>>v[i];
    sort(v,v+(1<<n));
    rep(i,m-1) st.insert(v[i]);

    vector<ll> slimes;
    slimes.push_back(v[m-1]);

    rep(day,n){
        //スライムは１日に1スライムしか生まないからvectorを入れ替えてシミュレート
        vector<ll> slimesNew=slimes;
        for(auto& x:slimes){
            //各スライムについてstに残っているそれより小さい最大のスライムを生成
            auto ite=st.lower_bound(x);

            if(ite==st.begin()){
                cout<<"No"<<endl;
                return 0;
            }
            ite--;
            slimesNew.push_back(*ite);
            st.erase(ite);
        }
        sort(ALL(slimesNew));
        reverse(ALL(slimesNew));
        swap(slimes,slimesNew);
    }

    //yesのほうがおかしい
    cout<<"Yes"<<endl;
    return 0;
}
