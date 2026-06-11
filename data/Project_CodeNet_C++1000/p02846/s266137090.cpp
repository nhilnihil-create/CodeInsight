#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    ll T1,T2;
    ll A1,A2;
    ll B1,B2;
    cin>>T1>>T2>>A1>>A2>>B1>>B2;
    if(A1 < B1){
        swap(A1,B1);
        swap(A2,B2);
    }
    ll ans = 0;
    if(A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2){
        cout<<"infinity";
    }
    else if(A1 * T1 + A2 * T2 < B1 * T1 + B2 * T2){
        ll x =B1 * T1 + B2 * T2 -A1 * T1 - A2 * T2;
        if((A1 * T1 - B1 * T1)%x == 0){
            ans -= 1;
        }
        ans += ((A1 * T1 - B1 * T1)/x) * 2;
        ans += 1;
        cout<<ans;
    }
    else{
        cout<<0;
    }
    return 0;
}