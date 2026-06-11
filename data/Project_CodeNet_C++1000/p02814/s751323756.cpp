// ABC150-D
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

    ll n,m;
    cin>>n>>m;
    int ans=0;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]/=2;
    } 
    bool flag=true;
    while(a[0]%2==0){
        rep(i,n){
            if(a[i]%2!=0){
                flag=false;
                break;
            }
            a[i]/=2;
        }
        m/=2;
    }
    rep(i,n) if(a[i]%2==0) flag=false;
    if(flag){
        ll lcm=a[0];
        for(int i=1;i<n;i++){
            lcm=lcm*a[i]/__gcd(lcm,a[i]);
            if(m<lcm){
                flag=false;
                break;
            }
        }
        if(flag){
            lcm=m/lcm;
            if(lcm%2==0) lcm--;
            ans=(lcm-1)/2+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}