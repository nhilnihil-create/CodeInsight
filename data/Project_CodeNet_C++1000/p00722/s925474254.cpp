#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

const int MAX_N = 1000006;
int a,d,n;
bool is_prime[MAX_N];
void init() {
    fill(is_prime,is_prime+MAX_N,true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < MAX_N; i++) {
        if(is_prime[i]) for(int j=i+i; j<MAX_N;j+=i) is_prime[j] = false;
    }
}
int main() {
    init();
    while(cin>>a>>d>>n) {
        int ans;
        if(a==0&&d==0&&n==0) break;
        while(n) {
            if(is_prime[a]) n--;
            if(n==0) ans = a;
            a+=d;
        }

        cout<<ans<<endl;

    }
    return 0;
}