#include<bits/stdc++.h>

using namespace std;
typedef long long ll;





//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define RALL(x) (x).rbegin(),(x).rend() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F firstw

#define S second
#define seq vector
#define READLINE(vec,time) for(int indexofvec=0;indexofvec<time;indexofvec++)cin>>vec[indexofvec]
#define VPRINT(vec) for(auto i : vec){cout << i<<" ";}cout<<endl;
#define lambda []
#define clambda [=]
#define reflambda [&]

template<typename A,typename B,class functype>
void select(vector<A>& in,vector<B>& out,functype func){
    out.resize(in.size());

    for(int i =0;i<in.size();i++){
        out[i]=func(in[i]);
    }


}








signed main(){

    string L;
    cin >>L;
    int len =L.length();
    vector<ll>dpl(len);
    vector<ll>dpc(len);
    dpc[0] = 2;
    dpl[0] = 1;

    for(int i =1;i<len;i++){

        if(L[i]=='1'){
            dpc[i]=(dpc[i-1]*2)%MOD;
            dpl[i] += ((dpl[i-1]*3)%MOD+ dpc[i-1])%MOD;
        }else if (L[i]=='0')
        {
            dpc[i]=(dpc[i-1]%MOD);
            dpl[i] += (dpl[i-1]*3)%MOD;
        }else{
            abort();
        }
    }

    cout << (dpc[len-1]+dpl[len-1])%MOD << endl;

}