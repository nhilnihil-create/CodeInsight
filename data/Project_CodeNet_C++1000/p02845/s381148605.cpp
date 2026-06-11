// 三井住友信託銀行プログラミングコンテスト2019-E
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

    ll n;
    cin>>n;
    ll mod=pow(10,9)+7,ans=1;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<int> back;
    ll g_num=0; //グループ数
    rep(i,n){
        if(a[i]==0){
            g_num++;
            back.e_b(0);
        }else{
            ll same_back=0;
            rep(j,g_num){
                if(back[j]==a[i]-1){
                    if(same_back==0) back[j]=a[i];
                    same_back++;
                }
            }
            ans*=same_back;
            ans%=mod;
        }
    }  
    ll num=3;
    for(int i=1;i<=g_num;i++){
        ans*=num;
        ans%=mod;
        num--;
    }
    cout<<ans<<endl;
    return 0;
}