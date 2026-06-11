#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;


int main () {
    int N;
    cin >> N;
    int A[N];
    vector<int> ans(N+1,0);
    rep(i,1,N+1) {
        cin >> A[i];
    }

    int M=0;
    for(int i=N; i>0; i--) {
        int tmp = i;
        int now = 0;
        int b = i;
        rep(j,1,N+10) {
            now+=ans[tmp];
            tmp+=b;
            if (tmp>N) {
                break;
            }
        }
        if(now%2==A[i]) {
            continue;
        }
        else {
            ans[i]++;
            M++;
        }
    }
    cout << M << endl;

    if (M>0) {

        rep(i,1,N+1) {
            if(ans[i]!=0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

}