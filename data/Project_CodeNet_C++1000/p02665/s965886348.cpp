// 
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
//typedef pair<int, int> pair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int num=pow(10,5)+1;
vector<ll> l(num);
vector<ll> r(num);
vector<ll> ad(num);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    rep(i,n+1) cin>>ad[i];
    l[n]=ad[n];
    r[n]=ad[n];
    if(n==0){
        if(ad[0]==1) cout<<1<<endl;
        else cout<<-1<<endl;
    }else{
        for(int i=n-1;i>=0;i=i-1){
            l[i]=ll(ceil(l[i+1]/2.0))+ad[i];
            r[i]=r[i+1]+ad[i];
        }
        // rep(i,n+1){
        //     cout<<l[i]<<" "<<r[i]<<endl;
        // }
        bool flag=true;
        ll ans=1;
        ll bef=1; //1つ上の層のノード数
        for(int i=1;i<=n;i++){
            ll max_ba=(bef-ad[i-1])*2; //上から見た時に層iに作れる子の数のmax
            if(max_ba<l[i]){
                flag=false;
                break;
            }
            bef=min(r[i],max_ba);
            ans+=bef;
        }
        if(flag) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}