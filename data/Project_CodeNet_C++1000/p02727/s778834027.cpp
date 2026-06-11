#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 100000

int main()
{
    int x,y;
    cin >> x >> y;
    int a,b,c;
    cin >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a)cin >> p[i];
    rep(i,b)cin >> q[i];
    rep(i,c)cin >> r[i];
    int j,k,l;
    j=0;k=0;l=0;
    ll ans=0;
    ll tmp;
    int x_lim,y_lim;
    x_lim=x;y_lim=y;
    int flag=0;
    rsort(p);rsort(q);rsort(r);
    rep(i,x+y){
        if(flag==0){
            if(p[j]>=q[k]&&p[j]>=r[l]){
                ans+=p[j];
                ++j;
                
                if(j==x){
                    flag=1;
                }
            }else if(q[k]>=p[j]&&q[k]>=r[l]){
                ans+=q[k];
                ++k;
                if(k==y){
                    flag=2;
                }
            }else{
                ans+=r[l];
                l++;
                if(l==c){
                    flag=3;
                }
            }
        }else if(flag==1){
            if(q[k]<r[l]){
                ans+=r[l];
                ++l;
                if(l==c){
                    flag=3;
                }
            }else{
                ans+=q[k];
                k++;
                if(k==y){
                    flag=4;
                }
            }
        }else if(flag==2){
            if(p[j]<r[l]){
                ans+=r[l];
                ++l;
                if(l==c){
                    flag=3;
                }
            }else{
                ans+=p[j];
                j++;
                if(j==x){
                    flag=4;
                }
            }
        }else if(flag==3){
            if(j<x||k<y){
                if(p[j]<q[k]){
                    ans+=q[k];
                    ++k; 
                }else{
                    ans+=p[j];
                    ++j;
                }
            }else if(j<x){
                ans+=p[j];
                ++j;
            }else if(k<y){
                ans+=q[k];
                ++k;
            }
        }
        else if(flag==4){
            ans+=r[l];
            ++l;
        }
    }
    cout << ans << endl;

}