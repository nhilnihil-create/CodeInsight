#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int A,B,m,x,y,c,mn=2e5;
    cin >> A >> B >> m;
    vector<int> a(A),b(B);
    rep(i,A)cin >> a.at(i);
    rep(i,B)cin >> b.at(i);
    rep(i,m){
        cin >> x >> y >> c;
        mn=min(a.at(x-1)+b.at(y-1)-c,mn);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    mn=min(mn,a.at(0)+b.at(0));
    cout << mn << endl;
}
