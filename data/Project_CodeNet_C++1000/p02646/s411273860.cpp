// 東京海上日動 プログラミングコンテスト2020-B
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll a,b,v,w,t;
    cin>>a>>v>>b>>w>>t;
    bool flag=true;
    if(v<=w) flag=false;
    else{
        ll ok=abs(b-a)/(v-w);
        if(abs(b-a)%(v-w)==0){
            if(t<ok) flag=false;
        }else{
            if(t<ok+1) flag=false;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}