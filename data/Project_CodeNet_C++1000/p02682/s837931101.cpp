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
double pi=2*acos(0.0);
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll sum=0;
    if(k){
        if(k>=a){
            sum+=a;
            k-=a;
        }
        else{
            sum+=k;
            k-=k;
        }
       
    }
    if(k){
        if(k>=b){
            k-=b;
        }
        else{
            k-=k;
        }
        
    }
    if(k){
        if(k==c){
            sum-=c;
        }
        else{
            sum-=k;
        }
        
    }
   
    cout<<sum;
}
