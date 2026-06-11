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
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int cnt[110000];

int main(){cout<<fixed<<setprecision(20);
		   string s;
           cin>>s;
           int n=s.size();
           int r=0,l=0;
           rep(i,0,n){
             if(s[i]=='R'){
              r++;
             }
             else{
               //cout<<r<<" "<<1<<endl;
              if(r>=1)cnt[i-1]=r;
               r=0;
             }
             //cout<<r<<endl;
           }
           for(int i=n-1;i>=0;i--){
            if(s[i]=='L')l++;
             else{
               
              if(l>=1)cnt[i+1]=l;
               l=0;
             }
           }
           
          // rep(i,0,n)cout<<cnt[i]<<endl;
           //cout<<endl;
           rep(i,0,n){
            if(cnt[i]){
             if(s[i]=='R'){
               int c=cnt[i+1];
               cout<<(cnt[i]+1)/2+c/2<<" ";
             }
              else{
                int c=cnt[i-1];
                cout<<(cnt[i]+1)/2+c/2<<" ";
              }
            }
             else{
               cout<<0<<" "; 
             }
           }
           //cout<<endl;
}

