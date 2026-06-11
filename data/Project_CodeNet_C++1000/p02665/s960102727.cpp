#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>
long INF = (1LL << 60);

int main() {
    int N;
    cin>>N;
    vi A(N+1);
    REP(i, 0, N+1){
        cin >> A[i];
    }
    
    if(N == 0){
        if(A[0] == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0; 
    }
    vl maxN(N+1, 0);
    vl node(N+1, 0);
    maxN[0] = 1;
    
    REP(i, 1, N+1){
        maxN[i] = (long)min((maxN[i-1] - A[i-1]) * 2, INF);
    }
    /*
    REP(i, 0, N+1) cout << maxN[i] << " ";
    cout << endl;
    */
    node[N] = A[N];
    for(int i = N-1; i >=0; i--){
        if(maxN[i] >= node[i+1] + A[i]){
            node[i] = node[i+1] + A[i];
        }else if(maxN[i] >= (long)(node[i+1]+1)/2 + A[i]){
            node[i] = maxN[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << accumulate(node.begin(), node.end(), 0LL) << endl;
}