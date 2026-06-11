// ABC134-D
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
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る

vector<bool> sh(200010,false);
vector<int> a(200010,0);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    int ball=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i=i-1){
        int j=i;
        int baisu=0;
        while(j<=n){
            if(sh[j]) baisu++;
            j+=i;
        }
        if(baisu%2!=a[i]) sh[i]=true,ball++;
    }
    cout<<ball<<endl;
    if(ball!=0){
        for(int i=1;i<=n;i++){
            if(sh[i]) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}