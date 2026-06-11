#include<bits/stdc++.h>
using namespace std;
const int mod = 200003;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define fr(s,n) for (int i=(int)(s);i<(int)(n);i++)
#define lc cout<<"\n"

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,flag=0;
    cin>>n;
    ll a[n];
    fr(0,n){
        cin>>a[i];
        if(a[i]==0){
            flag=1;
        }
    }
    if(flag){
        cout<<0;
    }
    else{
    ll s=1;
    fr(0,n){
        if(a[i]>1000000000000000000/s){
            s=-1;break;
        }
        s=s*a[i];
    }
    cout<<s;
    }
}
