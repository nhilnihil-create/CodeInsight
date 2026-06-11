#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

string s,t;
vector<int> v[30];

signed main(){
    cin>>s>>t;
    for(int i=0;i<s.size();++i)v[s[i]-'a'].push_back(i);
    int front=-1;
    int k=0;
    int cnt=0;
    while(k<t.size()){
        int c=t[k]-'a';
        if(v[c].size()==0){
            cout<<-1<<endl;
            return 0;
        }
        int idx=lower_bound(v[c].begin(),v[c].end(),front+1)-v[c].begin();
        if(idx==v[c].size()){
            cnt++;
            front=-1;
        }
        else {
            k++;
            front=v[c][idx];
        }
    }
    cout<<cnt*s.size()+front+1<<endl;
}