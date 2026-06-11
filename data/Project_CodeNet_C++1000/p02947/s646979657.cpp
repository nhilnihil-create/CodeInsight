// ABC137-C
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

    int n;
    cin>>n;
    vector<string> kind(n);
    rep(i,n){
        string s;
        cin>>s;
        sort(all(s));
        kind[i]=s;
    }
    sort(all(kind));
    ll ans=0;
    string bef="";
    ll ren=0;
    rep(i,n){
        if(bef!=kind[i]){
            if(ren>=2){
                ans+=ren*(ren-1)/2;
            }
            bef=kind[i];
            ren=1;
        }else{
            ren++;
        }
    }
    if(ren>=2){
        ans+=ren*(ren-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}