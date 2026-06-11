#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;
#define int long long
//#define double long double
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii > pip;
typedef pair<pii, pii > piipii;
typedef pair<double, double> pdd;
typedef pair<int, char> pic;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define all(vec) vec.begin(), vec.end()
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60)
#define mod 1000000007
#define se second
#define fi first

int T[2], A[2], B[2], S[2];

int abss(int aa){
    if(aa < 0)return -aa;
    return aa;
}

signed main(){
    cin >> T[0] >> T[1];
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    if(A[0] < B[0]){
        swap(A[0], B[0]);
        swap(A[1], B[1]);
    }
    S[0] = T[0] * A[0] - T[0] * B[0];
    S[1] = T[1] * A[1] - T[1] * B[1];
    
    if(S[0] + S[1] == 0){
        cout << "infinity" << endl;
        return 0;
    }
    if(S[0] + S[1] > 0){
        cout << 0 << endl;
        return 0;
    }
    int waru = abss(S[0] + S[1]);
    if(abss(S[0] % waru))cout << ((abss(S[0]) + waru - 1) / waru) * 2 - 1 << endl;
    else cout << ((abss(S[0]) + waru - 1) / waru) * 2 << endl;

    
    return 0;
}

/*

*/