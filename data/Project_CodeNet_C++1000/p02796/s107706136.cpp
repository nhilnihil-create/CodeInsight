#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
const ll inf=1e9+7;
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
ll lcm(ll a, ll b) { return a / (gcd(a, b)) * b; }

int n;
int main(){
    cin>>n;
    Q st(n);
    rep(i,0,n){
      int x,l;
      cin>>x>>l;
      st[i].first=x+l;
      st[i].second=x-l;
    }

    sort(st.begin(),st.end());

    int cnt=0,pos=st[0].second;
    rep(i,0,n){
      if(pos<=st[i].second){
        cnt++;
        pos=st[i].first;
      }
    }

    cout<<cnt<<endl;

    /*rep(i,0,n){
      cout<<st[i].first<<' '<<st[i].second<<endl;
    }*/

}