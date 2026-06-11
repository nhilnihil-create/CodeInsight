//Nice Shopping

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / __gcd(a, b) * b
#define range(a) (a).begin(),(a).end()
const int inf = 2147483647;

int main (){
    int A,B,M;cin >> A >> B >> M;
    vector<int> a(A),b(B);
    rep(i,0,A)cin >> a[i];
    rep(i,0,B)cin >> b[i];
    vector<vector<int>> x(M,vector<int>(3));
    rep(i,0,M)rep(j,0,3)cin >> x[i][j];
    int Ans = *min_element(range(a));
    Ans += *min_element(range(b));
    rep(i,0,M)Ans=min(Ans,a[x[i][0]-1]+b[x[i][1]-1]-x[i][2]);  
    cout << Ans <<endl;
    return 0;
}