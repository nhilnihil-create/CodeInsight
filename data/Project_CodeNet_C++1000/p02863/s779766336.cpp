
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <type_traits>
#include <locale>
#include <omp.h>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;
typedef pair<long long int, pll> lpll;

const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 
//const long long int pl=1000000;

long long int N,T,A[4000],B[4000],dp[4000][4000]={},res=0;
pll AB[4000];
int main(){

    cout << fixed << setprecision(18);
    cin>>N>>T;
    for(long long int i = 1; i <= N; i++){
        cin>>AB[i].first>>AB[i].second;
    }
    sort(AB+1,AB+N+1);
    for(long long int i = 1; i <= N; i++){
        for(long long int j = 0; j <= T-1; j++){
            if(j+AB[i].first<=T-1){
                dp[i][j+AB[i].first]=max(dp[i][j+AB[i].first],dp[i-1][j]+AB[i].second);
                
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            
        }
        res=max(res,dp[i-1][T-1]+AB[i].second);
    }
    //DEBUG_OUTPUT_ARRAY2_BOX(dp,11,101);
    cout<<res<<endl;
}

