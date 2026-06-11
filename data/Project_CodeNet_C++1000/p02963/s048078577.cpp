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
    ll S;
    cin>>S;
    ll x1, x2, y1, y2;
    x1 = 1000000000;
    y2 = (S-1)/x1+1;

    S = x1*y2 - S;
    y1 = 1;
    x2 = S;

    cout<<"0 0 "<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
    return 0;
}