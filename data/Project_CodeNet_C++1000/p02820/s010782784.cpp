// ABC144-D
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

    ll n,k;
    string t;
    map<char,ll> get={{'r',2},{'s',0},{'p',1}};
    cin>>n>>k;
    vector<bool> get_s(n,false);
    vector<ll> score(3);
    rep(i,3) cin>>score[i];
    cin>>t;
    ll total=0;
    rep(i,n){
        if(i<=k-1){
            total+=score[get[t[i]]];
            get_s[i]=true;
        }else{
            if(t[i]==t[i-k]){
                if(get_s[i-k]) continue;
                get_s[i]=true;
                total+=score[get[t[i]]];
            }else{
                total+=score[get[t[i]]];
                get_s[i]=true;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}