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
    priority_queue<ll> q;
    vector<pair<ll, ll> > works;
    ll N, M;
    ll A, B;
    cin>>N>>M;
    rep(i, N){
        cin>>A>>B;
        if(M>=A) works.push_back({A, B});
    }
    sort(all(works));
    ll index=0;
    ll count=0;
    rep1(i, M){
        //cout<<"#"<<i<<endl;
        //cout<<index<<endl;
        while(true){
            //cout<<works[index].second<<"$"<<endl;
            if(index>=works.size()) break;
            if(i!=works[index].first) break;
            q.push(works[index].second);
            index++;
        }
        //cout<<"And we will come back home, home again ..."<<endl;
        if(q.size()!=0){
            count+=q.top();
            //cout<<count<<endl;
            q.pop();
        }
    }
    cout<<count<<endl;
    return 0;
}
