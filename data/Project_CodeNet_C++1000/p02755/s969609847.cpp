#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi = vector<int>;
using vl= vector<ll>;
using vs=vector<string>;

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll max(ll a, ll b) {if (a > b) return a; else return b;}
ll min(ll a, ll b) {if (a < b) return a; else return b;}
ll power(ll a,ll b) {ll i,p=1; for(i=0;i<b;i++){p*=a;} return p;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
        ll a=0,b=0;
        cin>>a>>b;
        bool k=false;

	float c=a*12.5;
	float d=b*10;
	ll h=(int)min(c,d);
        //ll array[1010]={0};
        for(int i=h;i<1010;i++){
            if((floor(i*0.08))==a &&(floor(i*0.1)==b))
            {
                cout<<i;
                k=true;
                break;
            }
        }
        if(k==false)
        cout<<"-1";
        
        
        
        
        }

    return 0;
}
