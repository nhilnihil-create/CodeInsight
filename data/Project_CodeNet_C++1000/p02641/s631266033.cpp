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
    int x,n;
    cin>>x>>n;
    vi p;
    fr(0,n){
        int x;
        cin>>x;
        p.pb(x);
    }
    sort(all(p));
    for(int i=0;;i++){
        int a=x-i,b=x+i;
        if(find(all(p),a)==p.end()){
            cout<<a;
            break;
        }
        else if(find(all(p),b)==p.end()){
            cout<<b;
            break;
        }
    }

}



