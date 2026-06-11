#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long
using namespace std;
int enm(int n){
    int count=0,p=1;
    while(n>=0){
        n-=p;p++;count++;
        if(n-p<0)return count;
    }
};

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back(make_pair(a,ex));
    }

    // 最後に残った数について
    if (N != 1) res.push_back(make_pair(N,1));
    return res;
}


int main(){
    ll n;
    cin>>n;
    vector<pair< long long, long long> > x= prime_factorize(n);
    ll ans=0;
    for(int i=0;i<x.size();i++){
        ans+=enm(x[i].second);
    }
cout<<ans;
return 0;
}