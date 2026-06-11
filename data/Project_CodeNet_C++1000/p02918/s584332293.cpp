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
    INT(n,k);
    string s;
    cin>>s;
    int l=0,r=0,lpre=0,rpre=0;
    int l2=0,r2=0,lpre2=0,rpre2=0;
    vector<int> left,right;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            lpre=i;
            while(i<n&&s[i]=='L'){
                i++;
            }
            left.push_back(i-lpre);
            i--;
        }else{
            rpre=i;
            while(i<n&&s[i]=='R'){
                i++;
            }
            right.push_back(i-rpre);
            i--;
        }
    }
    if(s[0]=='R'){
        r=1;
        rpre=right[0];
    }
    if(s[0]=='L'){
        l=1;
        lpre=left[0];
    }
    if(s[n-1]=='R'){
        r2=1;
        rpre2=right[right.size()-1];
    }
    if(s[n-1]=='L'){
        l2=1;
        lpre2=left[left.size()-1];
    }
    if(k>=left.size()||k>=right.size()){
        out(n-1);
    }else{
        sort(rall(left));
        sort(rall(right));
        int leftsum=0,rightsum=0;
        for(int i=0;i<left.size();i++){
            leftsum+=left[i]-1;
        }
        for(int i=0;i<k;i++){
            leftsum+=right[i]+1;
        }
        for(int i=k;i<right.size();i++){
            leftsum+=right[i]-1;
        }
        for(int i=0;i<right.size();i++){
            rightsum+=right[i]-1;
        }
        for(int i=0;i<k;i++){
            rightsum+=left[i]+1;
        }
        for(int i=k;i<left.size();i++){
            rightsum+=left[i]-1;
        }
        out(max(leftsum,rightsum));
    }
}
