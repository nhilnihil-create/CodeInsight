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

    double a,b,x,t,ans;
    cin>>a>>b>>x;
    if(x/a<=a*b/2){
        t=2*x/(a*b);
        ans=atan(b/t)*180/M_PI;
    }else{
        t=(2*b*a*a-2*x)/(a*a);
        ans=atan(t/a)*180/M_PI;
    }
    cout<<ans<<endl;
    return 0;
}