#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	int k,q;
    cin>>k>>q;
    vi d(k);
    FOR(i,0,k){
        cin>>d[i];
    }
    vi n(q),x(q),m(q);
    FOR(i,0,q){
        cin>>n[i]>>x[i]>>m[i];
        LL ans=n[i]-1;
        vi aa(d),a(d);
        LL sm=0,cnt=0;
        LL n_mod_k=(n[i]-1)%k,nw=x[i]%m[i],rep=(n[i]-1)/k;
        FOR(j,0,k){
            aa[j]=aa[j]%m[i];
            if(aa[j]==0)cnt++;
            sm+=aa[j];
            if(j<n_mod_k){
                //cerr<<"j:"<<j<<" aa[j]:"<<aa[j]<<" nw:"<<nw<< endl;
                LL nx=(nw+aa[j])%m[i];
                if(nw>=nx){
                    ans--;
                }
                nw=nx;
            }
        }
        FOR(i,0,k){
            a[i]=aa[(i+n_mod_k)%k];
        }
        LL t=(nw+rep*sm)/m[i];
        //cerr<<"ans:"<<ans<<" t:"<<t<<" rep:"<<rep<<" sm:"<<sm<<" n_mod_k:"<<n_mod_k<< endl;
        ans-=t+rep*cnt;



        cout<<ans<<endl;
    }

}
