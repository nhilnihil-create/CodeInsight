#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector1d(type,name,...) vector<type>name(__VA_ARGS__)
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}

int main(){
    INT(h,w);
    vector2d(char,room,h,w);
    vector2d(int,tate,h,w,0);
    vector2d(int,yoko,h,w,0);
    in(room);
    int ans=0,j;
    rep(y,h){
        rep(x,w){
            if(room[y][x]=='.'){
                j=x;
                ans=0;
                while(j<w&&room[y][j]=='.'){
                    j++;
                    ans++;
                }
                for(;x<j;x++){
                    yoko[y][x]=ans;
                }
            }
        }
    }
    rep(x,w){
        rep(y,h){
            if(room[y][x]=='.'){
                j=y;
                ans=0;
                while(j<h&&room[j][x]=='.'){
                    j++;
                    ans++;
                }
                for(;y<j;y++){
                    tate[y][x]=ans;
                }
            }
        }
    }
    ans=0;
    rep(y,h){
        rep(x,w){
            ans=max(ans,tate[y][x]+yoko[y][x]-1);
        }
    }
    out(ans);
}