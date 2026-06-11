#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<int> A,B;
    rep(i,N) {
        int a,b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int ans = 0;

    if (N%2==1) {
        int a,b;
        a = A[N/2];
        b = B[N/2];
        ans = b-a+1;
    }
    else {
        int a = A[N/2] + A[N/2-1];
        int b = B[N/2] + B[N/2-1];
        ans = b-a+1;
    }
    cout << ans << endl;
}
