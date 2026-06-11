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
    int x,y;
    cin>>x>>y;
    int l=0,h=x;
    string ans="No";
    while(h>=l){
        int mid=(l+h)/2;
        int s=4*mid+2*(x-mid);
        if(s==y){
            ans="Yes";
            break;
        }
        else if(s>y){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
}



