#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> P;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
#define MAX 100000

ll n,x[MAX],l[MAX];
P xl[MAX] ;

int main(){

    cin>>n;
    
    rep(i,n){
        cin>>x[i];
        cin>>l[i+1];
        xl[i].first=x[i]+l[i+1];
        xl[i].second=x[i]-l[i+1];
        //cout<<xl[i].first<<" "<<xl[i].second<<endl;
    }
    sort(xl,xl+n);
    
    int count=0;
    ll  a=INT_MIN;
    rep(i,n){

        //cout<<xl[i].first<<" "<<xl[i].second<<endl;
        if(a<=xl[i].second){
            a=xl[i].first;
            
            count++;
        }
    }

    cout<<count;
    return 0;
    
}

