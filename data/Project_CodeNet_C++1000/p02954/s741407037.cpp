#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        ll l=1,r=0;
        while(s[i+1]=='R'){i++;l++;}
        while(s[i+1]=='L'&&i<s.size()-1){i++;r++;}
        ll fir=(l+r)/2,sec=fir;
        if((l+r)&1){
            ll len=max(l-1,r-1);
            if(len&1&&l<r||len%2==0&&r<l)fir++;
            else sec++;
        }
        //cout<<l<<" "<<r<<" "<<fir<<" "<<sec<<"\n";
        for(int j=i-l-r+1;j<=i;j++){
            if(s[j]=='R'&&s[j+1]=='L'){cout<<fir<<" "<<sec<<" ";j++;}
            else cout<<"0 ";
        }
    }
}
