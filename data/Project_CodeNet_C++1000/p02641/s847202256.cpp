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
    int x,n,a,ans;
    int A[202]={};
    cin>>x>>n;
    REP(i,n){
        cin>>a;
        A[101-(x-a)]++;
    }
    REP(i,101){
        if(A[101-i]==0){
            ans=x-i;
            break;
        }
        else if(A[101+i]==0){
            ans=x+i;
            break;
        }
    }
    cout<<ans<<endl;
}