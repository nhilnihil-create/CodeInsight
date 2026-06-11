#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;

string s;
string head;
string tail;
int Q;
int d=0;

int main(){
    
    cin >> s;
    cin >> Q;
    rep(i,Q){
        int q;
        cin >> q;
        if(q==1){
            d=(d+1)%2;
        }else if(q==2){
            int f;
            char t;
            cin >> f>>t;
            if((d+f)%2==0){
                tail=tail+t;
            }else{
                head=t+head;
            }
        }
    }
    s=head+s+tail;
    if(d==0){
        cout << s<<endl;
    }else{
        int n=s.size();
        rep(i,n){
            cout << s[n-1-i];
        }
        cout << endl;
    }
    return 0;
}