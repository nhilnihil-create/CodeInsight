#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    int N; cin >> N;
    vi x(N), y(N);
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i];
    }
    vi ord(N);
    for(int i=0; i<N; i++) ord[i]=i;
    double avg=0;
    do{
        for(int i=0; i<N-1; i++){
            double dx, dy;
            dx=x[ord[i+1]]-x[ord[i]];
            dy=y[ord[i+1]]-y[ord[i]];
            avg+=sqrt(dx*dx+dy*dy);
        }
    }while(next_permutation(all(ord)));
    for(int i=1; i<=N; i++){
        avg/=i;
    }
    cout << fixed << setprecision(7);
    cout << avg << endl;
    return 0;
}