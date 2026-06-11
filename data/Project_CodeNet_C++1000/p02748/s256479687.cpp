#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);

int main(){
    int a,b,m;
    cin>>a>>b>>m;
    vector<int> fri(a),ran(b);
    con_input(fri);
    con_input(ran);
    int x,y,c,minv;
    rep(i,m){
        cin>>x>>y>>c;
        if(i==0)minv=fri[x-1]+ran[y-1]-c;
        else{
            minv=min(minv,fri[x-1]+ran[y-1]-c);
        }
    }
    sort(all(fri));
    sort(all(ran));
    minv=min(minv,fri[0]+ran[0]);
    cout<<minv<<endl;
}