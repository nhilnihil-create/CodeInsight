#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    vin a(n);rep(i,n)cin>>a[i];
    vin boll(n+1);int sum;
    queue<int> one;
    for(int i=n;i>0;i--){
        sum=0;
        for(int j=2*i;j<=n;j+=i)sum+=boll[j];
        if(a[i-1]%2==sum%2)boll[i]=0;
        else{
            boll[i]=1;
            one.push(i);
        }
    }
    cout<<one.size()<<endl;
    while(one.size()>1){
        cout<<one.front()<<" ";
        one.pop();
    }
    if(one.size())cout<<one.front()<<endl;
}