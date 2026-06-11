#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
 
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};
 
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int mod=1000000007;

string L;
int N;
int mo=1000000007;
int S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//cin>>L;
	L="0"+L;
	N=L.size();
	int ret=0;
	int v=1,a=1;
	
	int c=1;
	S[0]=1;
	for(int i=0;i<N;++i) {
		S[i+1]=S[i];
		if(L[i]=='1') S[i+1]=S[i+1]*2%mo;
	}
	
	for(i=N-1;i>=1;i--) {
		if(L[i]=='1') {
			v=v*2%mo;
			ret+=a*S[i]%mo;
		}
		a=a*3%mo;
	}
	ret+=v;
	cout<<(ret%mo)<<endl;
}

PI ab[4]={PI(0,0),PI(0,1),PI(1,0),PI(1,1)};
int mem[100005][2][3];

void init(){
    for(int i=0;i<100005;++i)for(int j=0;j<2;++j)for(int k=0;k<3;++k)mem[i][j][k]=-1;
}

int check(int a, int b, int c, int dig){
    if(a+b+c>L[dig]-'0')return 2;
    if(a+b+c==L[dig]-'0')return 1;
    else return 0;
}

// isequal : 0=small, 1=equal, 2=bigger 
int calc(int n, int pre_c, int isequal,PI res){
    if(mem[n][pre_c][isequal]!=-1)return mem[n][pre_c][isequal];
    int ret=0;
    int a,b,c;
    int isequal_;
    /*cout<<"n="<<n<<endl;
    cout<<"a="<<res.first<<" b="<<res.second<<endl;
    cout<<"isequal="<<isequal<<endl;*/
    //i桁目が0のとき
    //ai+bi=1かつai-1+bi-1=1 または ai+bi=0かつai-1+bi-1=0
    //ai^bi=0 -> ai=0かつbi=0 または ai=1かつbi=1
    //
    //i桁目が1のとき
    //ai+bi=0かつai-1+bi-1=1 または ai+bi=1かつai-1+bi-1=0
    //ai^bi=1 -> ai=0かつbi=1 または ai=1かつbi=0
    /*if(pre_a==0&&pre_b==0){
        a=0,b=0,c=0;
        if(isequal==0||isequal==2)isequal_=isequal;
        else isequal_=check(a,b,pre_c,n);
        if(!(n==N-1&&isequal_==2))ret+=calc(n+1,a,b,c,isequal_);
        ret%=mod;
        a=1,b=1,c=1;
        if(isequal==0||isequal==2)isequal_=isequal;
        else isequal_=check(a,b,pre_c,n);
        if(!(n==N-1&&isequal_==2))ret+=calc(n+1,a,b,c,isequal_)+1;
        ret%=mod;
    }
    //i桁目が1のとき
    //ai+bi=0かつai-1+bi-1=1 または ai+bi=1かつai-1+bi-1=0
    //ai^bi=1 -> ai=0かつbi=1 または ai=1かつbi=0
    if(pre_a+pre_b==0){
        a=0,b=1;
        if(isequal==0||isequal==2)isequal_=isequal;
        else isequal_=check(a,b,pre_a,pre_b,n);
        if(!(n==N-1&&isequal_==2))ret+=calc(n+1,a,b,isequal_)+1;
        ret%mod;
        a=1,b=0;
        if(isequal==0||isequal==2)isequal_=isequal;
        else isequal_=check(a,b,pre_a,pre_b,n);
        if(!(n==N-1&&isequal_==2))ret+=calc(n+1,a,b,isequal_)+1;
        ret%=mod;
    }*/
    if(n==N)return 0;
    for(int i=0;i<4;++i){
        a=ab[i].first,b=ab[i].second;
        PI next=PI(res.first+(a<<n),res.second+(b<<n));
        if(a+b+pre_c>=2)c=1;
        else c=0;
        int same=check(a,b,pre_c,n);
        if(isequal==0||isequal==2){
            if(same==1)isequal_=isequal;
            else isequal_=same;
        }
        else isequal_=check(a,b,pre_c,n);
        if((a+b+pre_c)%2==a^b){
            if(!(n==N-1&&isequal_==2)){
                if((a==0&&b==0)||c!=0)ret+=calc(n+1,c,isequal_,next);
                else ret+=calc(n+1,c,isequal_,next)+1;
            }
            ret%=mod;
        }
    }
    return mem[n][pre_c][isequal]=ret%mod;
}

signed main(){
    init();
    cin>>L;
    N=L.size();
    reverse(L.begin(),L.end());
    cout<<(calc(0,0,1,PI(0,0))+1)%mod<<endl;
    reverse(L.begin(),L.end());
    //solve();
    return 0;
}
