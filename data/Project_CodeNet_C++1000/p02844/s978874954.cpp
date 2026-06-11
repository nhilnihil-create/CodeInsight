#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll n;
string s;

int main(){
    cin >> n >> s;
    ll res=0;
    for(ll i=0;i<1000;i++){
        ll a=i/100;
        ll b=(i%100)/10;
        ll c=i%10;
        bool flag=false;
        bool aa=false;
        bool bb=false;
        bool cc=false;
        for(ll i=0;i<n;i++){
            if(!aa&&s[i]-'0'==a) aa=true;
            else if(aa&&!bb&&s[i]-'0'==b) bb=true;
            else if(aa&&bb&&!cc&&s[i]-'0'==c){
                cc=true;
                flag=true;
                break;
            }
        }
        if(flag) res++;
    }
    cout << res << endl;
    return 0;
}  
