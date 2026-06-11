#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 

int main(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int R = 0;
    int G = 0;
    int B = 0;
    REP(i, N) {
        if (S[i] == 'R') R++;
        else if (S[i] == 'G') G++;
        else B++;
    }

    ll ret = (ll)R * G * B;
    FORE(l, 1, N) {
        REP(i, N) {
            int j = i+l;
            int k = j+l;
            if (j < N && k < N) {
                if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k])
                    --ret;
            }
        }
    }
    cout << ret << endl;
    
    return 0;
}
