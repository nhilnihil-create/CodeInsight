#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << "No" << endl;
        return 0;
    }
    int s = 1;
    int m = 0;
    rep(i,30){
        if(s-1<=n){
            m = s-1;
        }
        s*=2;
    }
    
    //cerr << n << " " << m << endl;
    vector<pair<int,int> > v;
    
    for(int i=1;i<m;i++){
        v.PB(MP(i,i+1));
    }
    v.PB(MP(m,n+1));
    for(int i=1;i<m;i++){
        v.PB(MP(n+i,n+i+1));
    }
    if((n-m)%2==0){
        for(int i=m+1;i<=n;i+=2){
            int k = i^(i+1);
            v.PB(MP(k,i));
            v.PB(MP(k,i+1));
            v.PB(MP(i,i+n+1));
            v.PB(MP(i+1,i+n));
        }
    }else{
        if(n-m==1){
            cout << "No" << endl;
            return 0;
        }else{
            v.PB(MP(m+3,m+2));
            v.PB(MP(m+2,1));
            v.PB(MP(m+2,m+1));
            v.PB(MP(2,n+m+3));
            v.PB(MP(n+m+3,n+m+2));
            v.PB(MP(1,n+m+1));
            for(int i=m+4;i<=n;i+=2){
                int k = i^(i+1);
                v.PB(MP(k,i));
                v.PB(MP(k,i+1));
                v.PB(MP(i,i+n+1));
                v.PB(MP(i+1,i+n));
            }
        }
    }
    cout <<"Yes" << endl;
    for(auto x:v){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}