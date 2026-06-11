#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int N,M;
    cin >> N >> M;
    int A[N],B[N];
    vector<P> v;
    rep(i,N){
        cin >> A[i] >> B[i];
        v.push_back(make_pair(B[i],A[i]));
    }
    sort(v.begin(),v.end(),[](P& lhs, P& rhs){return lhs.second < rhs.second;});
    priority_queue<P,vector<P> > q;
    ll ans = 0;
    int ind=0;
    rep(now,M){
        while(now+1==v[ind].second && ind<v.size()){
            q.push(v[ind]);
            ind++;
        }
        if(q.empty()) continue;
        P p = q.top();q.pop();
        ans += p.first;
    }
    cout << ans << endl;
    return 0;
}