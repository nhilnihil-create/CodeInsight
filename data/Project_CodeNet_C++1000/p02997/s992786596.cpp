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

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll N, K;
    cin>>N>>K;
    if((N-2)*(N-1)/2<K) cout<<-1<<endl;
    else{
        ll oth=(N-2)*(N-1)/2-K;
        cout<<oth+N-1<<endl;
        rep1(i, N-2) reps(j, i+1, N){
            if(oth==0) break;
            cout<<i<<sp<<j<<endl;
            oth--;
        }
        rep1(i, N-1){
            cout<<i<<sp<<N<<endl;
        }
    }
    return 0;
}
