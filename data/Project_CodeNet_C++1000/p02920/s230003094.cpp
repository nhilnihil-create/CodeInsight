#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N;
    int a;
    vector<int> S;
    cin >> N;
    REP(i,(1<<N)){
        cin >> a;
        S.push_back(a);
    }
    sort(S.begin(),S.end(),greater<>());
    //REP(i,S.size()){cout << S[i] << " ";}cout << endl;
    priority_queue<pair<int,int>> Q;
    multiset<int> T;
    REP(i,S.size()){
        if(i==0)continue;
        T.insert(S[i]);
    }
    RREP(i,N){
        Q.push({i,S[0]});
    }
    while(!Q.empty()){
        pair<int,int> q=Q.top();
        Q.pop();
        //cout << q.first MM q.second << endl;
        auto it = T.lower_bound(q.second);
        it--;
        if(it==T.end())GOODBYE;
        int r = *it;
        it = T.erase(it);
        //cout << "!? " MM r << endl;
        if(r>=q.second)GOODBYE;
        RREP(i,q.first){
            Q.push({i,r});
            //cout << "! " MM i MM r << endl;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}

