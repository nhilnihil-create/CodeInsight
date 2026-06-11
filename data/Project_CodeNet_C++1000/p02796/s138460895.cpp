#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

#define MAX_NUM 100000

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    P p[MAX_NUM];
    rep(i, n){
        int x, l;
        cin >> x >> l;
        p[i].first = x+l;
        p[i].second = x-l;
    }
    sort(p, p+n);
    
    int res=0;
    int x=p[0].first;
    for(int i=1; i<n; i++){
        if(x>p[i].second){
            res++;
        }else{
            x=p[i].first;
        }
    }
    
    cout << n - res << endl;
    
    return 0;
}
