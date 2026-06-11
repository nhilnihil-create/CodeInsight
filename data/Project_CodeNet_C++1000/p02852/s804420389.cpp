#include <bits/stdc++.h>
using namespace std;
    
#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
    
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
    
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
    
const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
    
int main(){
    LL N, M;
    string S;
    cin >> N >> M >> S;

    int valid_check = 0;
    REP(i, N+1) {
        if(S[i] == '1') {
            valid_check++;
            
            if(valid_check == M) {
                cout << -1 << endl;
                return 0;
            }
        } else {
            valid_check = 0;
        }
    }

    int prev[100002];
    int cnt[100002];
    prev[0] = -1;

    REP(i, M) {
        if(S[i+1] == '0') {
            prev[i+1] = 0;  
            cnt[i+1] = 1; 
        } else {
            cnt[i+1] = -1;
        }
    }

    VLL skip_index_vec;
    REP1(i, N+1) {
        if (S[i] == '0') {
            REP(j, skip_index_vec.size()) {
                int step = skip_index_vec[j] - i;
                prev[skip_index_vec[j]] = i;
                cnt[skip_index_vec[j]] = cnt[i] + 1;
            }
            skip_index_vec.clear();
            if(i+M < N+1 && S[i+M] == '0') {
                prev[i+M] = i;
                cnt[i+M] = cnt[i] + 1;
            }
        } else if (i+M < N+1  && S[i+M] == '0') {
            skip_index_vec.PB(i+M);
        }
    }

    stack<int> ans;
    int idx = N;
    while(prev[idx] != -1) {
        ans.push(idx - prev[idx]);
        idx = prev[idx];
    }

    while(!ans.empty()) {
        int out = ans.top(); ans.pop();
        cout << out << (ans.empty() ? "\n" : " ");
    }
}