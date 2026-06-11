#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

int main(){
    int N; cin >> N;
    vi A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
    sort(all(A));
    sort(all(B));
    int res=0;
    if(N%2 == 1){
        int id=(N-1)/2;
        res=B[id]-A[id]+1;
        cout << res << endl; 
    }
    else{
        int id1=(N-2)/2, id2=N/2;
        res=B[id2]-A[id2]+1+B[id1]-A[id1];
        cout << res << endl;
    }
    return 0;
}