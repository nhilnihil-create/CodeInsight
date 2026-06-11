#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vll vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
//以上テンプレ

int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    ll s1,s2;
    s1=a1-b1;
    s2=a2-b2;
    if(s1<0){
        s1*=-1;
        s2*=-1;
    }
    ll count=0;
    ll dis=0;
    ll check=0;//0か1か-1
        if(s1*t1+s2*t2==0){
            cout<<"infinity"<<endl;
            return 0;
        }
        else if(s1*t1+s2*t2>0){
            cout<<0<<endl;
            }else{
                ll a,b;
                ll c=(s1*t1+s2*t2)*-1;
                a=s1*t1/c;
                b=s1*t1%c;
                if(b==0){
                    cout<<a*2<<endl;
                }else{
                    cout<<a*2+1<<endl;
                }
        }
}