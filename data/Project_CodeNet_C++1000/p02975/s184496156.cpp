#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N;
    cin>>N;
    map<ll,ll> m;
    vector<ll> a(N);
    for(ll i=0;i<N;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a.begin(),a.end());
    if(m[0]==N){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(N%3!=0){
        cout<<"No"<<endl;
        return 0;
    }
    if(m[0]==N/3&&m[a[N-1]]==N*2/3){
        cout<<"Yes"<<endl;
        return 0;
    }
    ll cnt=0;
    for(ll i=0;i<N;i++){
        if(m[a[i]]!=N/3){
            cout<<"No"<<endl;
            return 0;
        }
    }
    bitset<30> b1(a[0]),b2(a[N/3]),b3(a[N-1]),B;
    B=b1^b2;
    B^=b3;
    if(B==0){
        if(m[a[0]]==N/3&&m[a[N-1]]==N/3){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
