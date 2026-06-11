#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>
using namespace std;
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < (int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;

int main(int argc, char* argv[])
{
    int n;
    int ans[100] = {0};
    int y,m,d;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> y >> m >> d;
        if(y%3 == 0){
            ans[i] += (10 - m)*20+(21-d);
        }else{
            if(m%2 == 0){
                ans[i] += (20-d);
                ans[i] +=( (10-m)/2 )*19;
                ans[i] += ((10-m) - ((10-m)/2)) * 20;
                ans[i] += 5;
            }else {
                ans[i] += (21-d);
                ans[i] += ( (10-m)/2 )*20;
                ans[i] += ((10-m) - ((10-m)/2)) * 19;
                ans[i] += 5;
            }
        }
        
        ans[i] += (999 - y) / 3 * 200;
        ans[i] += ((999-y) - (999 - y)/3) * 195;
        
    }
    for (int i=0; i<n; i++) {
        cout << ans[i] << endl;
    }
    
    
    
    
    return 0;
}