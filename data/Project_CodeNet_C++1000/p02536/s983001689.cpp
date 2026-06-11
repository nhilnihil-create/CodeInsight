#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';

using namespace boost::multiprecision;
using namespace std;
using namespace atcoder;

int main(void){
    ll N, M;
    cin>>N>>M;
    ll a, b;
    dsu d(N);
    rep(i, M){
        cin>>a>>b;
        d.merge(a-1, b-1);
    }
    cout<<(d.groups().size())-1<<endl;
    return 0;
}
