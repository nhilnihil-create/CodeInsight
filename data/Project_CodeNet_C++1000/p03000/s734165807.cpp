#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,x;
    cin>>n>>x;
    int cnt=1;
    int lc=0;
    rep(i,n){
        int l;
        cin>>l;
        lc+=l;
        if(lc<=x) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}