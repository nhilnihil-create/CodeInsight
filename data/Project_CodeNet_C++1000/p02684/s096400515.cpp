#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <utility>
using namespace std;
int ky[8] = {-1,1,-2,2,-2,2,-1,1}; 
int kx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ddy[8] = {-1,0,1,-1,1,-1,0,1};
int ddx[8] = {-1,-1,-1,0,0,1,1,1};
typedef long long ll;
#define pi pair
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define rep1(i,a,b) for(int i = a; i < b; i++)
#define rep2(i,a,b) for(int i = a; i <= b; i++) 
#define INF 9999999999999
const double PI = acos(-1.0);
int N;
int a[200001];
bool vis[200001];
vector<int> v;
vector<int> r;
ll K;
ll loop;
int vs,rs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N >> K;
    rep2(i,1,N) cin >> a[i];

    int here = 1;
    while(!vis[here]){
        vis[here] = true;
        v.PB(here);
        here = a[here];
    }

    vs = v.size();
    rep1(i,0,vs){
        if(v[i] == here){
            rep1(j,i,vs) r.PB(v[j]);
            break;
        }
    }
    rs = r.size();

    if(K < vs){
        loop = K % vs;
        cout << v[loop];
    }
    else{
        loop = (K - vs) % rs;
        cout << r[loop];
    }
    return 0;
}
