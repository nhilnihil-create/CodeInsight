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

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';
using namespace std;

unordered_map<ll, ll> soinsu;

void bunkai_to_prime(ll index){
    reps(i, 2, sqrt(index)+1){
        while(index%i==0){
            index/=i;
            soinsu[i]++;
        }
        if(index==1) break;
    }
    if(index!=1) soinsu[index]++;
}

int main(void){
    ll N;
    cin>>N;
    bunkai_to_prime(N);
    //cout<<N<<endl;
    ll count=0;
    for(auto a : soinsu){
        //cout<<a.second<<sp;
        count+=(ll)((sqrt(1+8*(double)a.second)-1)/2);
    }
    cout<<count<<endl;
    return 0;
}
