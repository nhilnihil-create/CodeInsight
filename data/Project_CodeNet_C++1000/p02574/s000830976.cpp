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
#define INF 999999999999
const double PI = acos(-1.0);
int n;
int a[1000001];
int ret;
int num;
bool ok;
int cnt;

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    rep1(i,0,n){
        cin >> num;
        a[num]++;
        ret = gcd(ret,num);
    }

    for(int i = 2; i <= 1000000; i++){
        cnt = 0;
        for(int j = i; j <= 1000000; j += i) cnt += a[j];
        if(cnt > 1){
            ok = true;
            break;
        }
    }

    if(!ok) cout << "pairwise coprime";
    else if(ret == 1) cout << "setwise coprime";
    else cout << "not coprime";

	return 0;
}