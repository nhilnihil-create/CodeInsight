#include<bits/stdc++.h>
using namespace std;
#define For(i,n,k) for(int i=(n);i<(k);i++)
typedef long long ll;
vector<int> div(int x){
    vector<int> ret;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            ret.emplace_back(i);
            if(i*i!=x) ret.emplace_back(x/i);
        }
    }
    sort(ret.rbegin(),ret.rend());
    return ret;
}
int main(){
    int n,k;
    cin >> n >> k;
    int sum=0;
    vector<int> a(n);
    For(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> divs = div(sum);
    for(auto x:divs){
        vector<ll> p;
        For(i,0,n){
            if(a[i]%x){
                p.emplace_back(a[i]%x);
            }
        }
        if(p.size()==0){
            cout << x << endl;
            return 0;
        }
        sort(p.begin(),p.end());
        ll l=0,r=x*p.size() - accumulate(p.begin(),p.end(),0);
        ll cnt = 1e9;
        For(i,0,p.size()){
            l+=p[i];
            r-=(x-p[i]);
            if(l%x == r%x)cnt = min(cnt,max(l,r));
        }
        if(cnt<=k){
            cout << x << endl;
            return 0;
        }
    }
}