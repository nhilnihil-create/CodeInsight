#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
struct V{
   double x,y;
   //0で初期化
   V(double x=0.0,double y=0.0):x(x),y(y) {}
   V& operator+=(const V& v){ x+=v.x; y+=v.y;   return *this; }
   V operator+(const V& v) const{return V(*this)+=v;}
   //内積
   double dot(const V& v) const{return x*v.x+y*v.y;}
   //外積
   double cross(const V& v)const{return x*v.y-v.x*y;}
   //長さの２乗
   double norm2() const{return x*x+y*y;}
   //長さ
   double norm()const{return sqrt(norm2());}
   //象限(orthant)
   int ort() const{
     if(y>0)return x>0?1:2;
     else   return x>0?4:3;
   }
   //偏角ソートのための比較関数
   bool operator<(const V& v) const{//反時計回りを正
       int o=ort(),vo=v.ort();
       if(o!=vo)return o<vo;
       else return cross(v)>0;
       }
};
istream& operator>>(istream& is,V& v){//cinで読み込める
    is>>v.x>>v.y;  return is;
}
ostream& operator<<(ostream& os,const V& v){//出力
   os<<"("<<v.x<<","<<v.y<<")";return os;
}
int main(){
    int n;
    cin>>n;
    vector<V> v(n);
    for(int i=0;i<n;i++)cin>>v[i]; 
   // for(int i=0;i<n;i++)cout<<v[i]<<endl;
    sort(all(v));
    double ans=0.0;
    for(int i=0;i<n;i++){
        int r=i;
        V now;
        for(int j=0;j<n;j++){
            now+=v[r];
            ans=max(ans,now.norm());
            r=(r+1)%n;
        }
    }
    printf("%.12f\n",ans);
    return 0;
}
