#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;


int main(){
    int n,k,c;
    string s;
    int A[200005]={},B[200005]={};
    cin>>n>>k>>c>>s;
    int i=0,cnt=1;
    while(cnt<=k && i<n){
        if(s[i]-'o'==0){
            A[i]=cnt;
            cnt++;
            i+=c;
        }
        i++;
    }
    i=n-1;
    int cnt2=k;
    while(i>=0&&cnt2>0){
        if(s[i]-'o'==0){
            B[i]=cnt2;
            cnt2--;
            i-=c;
        }
        i--;
    }
    REP(i,n){
        if(A[i]!=0&&A[i]==B[i]) cout<<i+1<<endl;
    }
    
}