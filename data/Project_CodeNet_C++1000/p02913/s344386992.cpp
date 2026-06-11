#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
#define PI 3.1415926535897932386
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int Zalgorithm(string s){
    vector<int> Z(s.size());
    Z[0] = s.size();
    int i = 1, j = 0;
    while(i < s.size()){
        while(i + j < s.size() && s[j] == s[i + j]) j++;
        Z[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(k < j && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    int m=0;
    REP(i,SZ(s)){
        m=max(m,min(Z[i],i));
    }
    return m;
}
int main(){
    int n;
    string s;
    cin>>n>>s;
    string t="";
    int ans=0;
    REP(i,n){
        t=s[n-i-1]+t;
        ans=max(ans,Zalgorithm(t));
    }
    OUT(ans);
    return 0;
}