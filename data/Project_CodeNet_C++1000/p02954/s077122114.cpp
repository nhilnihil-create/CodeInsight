#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    string s;
    cin >> s;
    int n=s.size();
    vector<int> x(n);
    {
        int j=0;
        REP(i,n){
            x[j]++;
            if(s[i]==s[i+1])continue;
            j++;
        }
        x.resize(j);
    }
    {
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R' && s[i+1]=='L'){
                printf("%d %d ",(int)ceil((double)x[j]/2)+x[j+1]/2,(int)ceil((double)x[j+1]/2)+x[j]/2);
                i++;j+=2;
            }
            else printf("0 ");
        }
    }
    return 0;
}