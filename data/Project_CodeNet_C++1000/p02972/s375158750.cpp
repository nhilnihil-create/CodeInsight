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

vector<int> a(200010,0);
vector<int> c(200010,0); 
vector<bool> sh(200010,false); //ボールを入れる
int ball=0;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    rep(i,n) cin>>a[i+1];
    for(int i=n;i>=1;i=i-1){
        if(c[i]%2!=a[i]){
            ball++;
            sh[i]=true;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    c[j]++;
                    if(j*j!=i) c[i/j]++;
                }
            }
        }
    }
    cout<<ball<<endl;
    if(ball!=0){
        rep(i,n){
            if(sh[i+1]) cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}