#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;


int main(){
    ll N;
    cin>>N;
    ll NN=N-1;
    ll RN=pow(N, 0.5);
    ll Cou=0;
  	
  	//cout<<"RN="<<RN<<endl;
    for(ll i=1; i<=RN; i++){
        if(N%i==0){
            ll ri=N/i;
            ll A=N;
            ll B=N;
            while(A%i==0&&i>1){
                A/=i;
            }
            A%=i;
            if(A==1&&i>1){
			Cou++;
            //cout<<i<<endl;
            }
            while(B%ri==0){
                B/=ri;
            }
            B%=ri;
            if(B==1&&i!=ri){
              Cou++;
              //cout<<ri<<endl;
            }
            
        }
        if(NN%i==0){
            //cout<<i<<endl;
          	//cout<<NN/i<<endl;
          	Cou+=2;
            if(i==1)Cou--;
          	if(i*i==NN)Cou--;
        }
    }
    cout<<Cou<<endl;
}

