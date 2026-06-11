#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(20);
		   ll t1,t2;
           ll a1,a2;
           ll b1,b2;
           cin>>t1>>t2>>a1>>a2>>b1>>b2;
           if(a1<b1){
             swap(a1,b1);
             swap(a2,b2);
           }
           if(t1*(a1-b1)+t2*(a2-b2)==0){
            cout<<"infinity"<<endl;
             return 0;
           }
           if(a1*t1+a2*t2>b1*t1+b2*t2){
            cout<<0<<endl;
             return 0;
           }
           ll sa=(a1*t1+a2*t2-(b1*t1+b2*t2));
           sa*=-1;
           if((a1*t1-b1*t1)%sa==0){
             cout<<(a1*t1-b1*t1)/sa*2<<endl;
           }
           else{
           cout<<(a1*t1-b1*t1)/sa*2+1<<endl;
           }
}