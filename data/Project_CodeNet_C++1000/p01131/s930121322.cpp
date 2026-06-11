#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v),end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;

template<typename A,typename B> inline void chmin(A &a,B b){if(a>b) a=b;}
template<typename A,typename B> inline void chmax(A &a,B b){if(a<b) a=b;}
//-----------------------------------------------------------------------

string table[10]={"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

int n; cin>>n;
while(n--)
{
    string s; cin>>s;
    int cnt=0,idx;
    REP(i,s.size()){
        if(s[i]!='0'){
            cnt++;
            idx=s[i]-'0';
        } else{
            if(cnt>0) cout<<table[idx][(cnt-1)%table[idx].size()];
            cnt=0;
        }
    }
    cout<<endl;
}
}