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
//double pi=2*acos(0.0);
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n]={0};
    fr(0,k){
        int d;
        cin>>d;
        for(int j=0;j<d;j++){
            int x;
            cin>>x;
            a[x-1]=1;
        }
    }
    int ans=0;
    fr(0,n){
        ans+=!a[i];
    }
    cout<<ans;
}

