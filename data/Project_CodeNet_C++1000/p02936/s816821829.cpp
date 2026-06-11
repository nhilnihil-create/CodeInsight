#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

void search_depth(vector<ll>& ans, vector<int>& flag, vector< vector<int> >& vt, int next_p, ll tmp, map<int,int>& M){
    tmp+=M[next_p];
    ans[next_p]=tmp;
    flag[next_p]=1;
    for(auto nt: vt[next_p]){
        if(flag[nt]==0) search_depth(ans, flag, vt, nt, tmp, M);
    }
}

int main(){
    int N,Q;
    cin >> N >> Q;
    vector< vector<int> > vt(N);
    vector<int> flag(N,0);
    map<int,int> M;
    for(int i=0,a,b; i<N-1; i++){
        cin >> a >> b;
        a--;b--;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(int i=0,p,x; i<Q; i++){
        cin >> p >> x;
        p--;
        M[p]+=x;
    }
    vector<ll> ans(N,0);

    search_depth(ans, flag, vt, 0, 0, M);
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i] << ' ';
    }
    cout << ans[ans.size()-1] << endl;




    return 0;
}