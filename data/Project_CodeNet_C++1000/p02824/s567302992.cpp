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


const long long int mod = 998244353;
const long long int INF = 1e18;




long long int N,M,V,P,A[100050],res=0,line=0,sum[100050]={};

char ch;


int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>M>>V>>P;
    for(long long int i = 1; i <= N; i++){
        cin>>A[i];
    }
    sort(A+1,A+N+1);
    res+=P;
    line=A[N-P+1];
    for(long long int i = N; i >= 1; i--){
        sum[i]=sum[i+1]+A[i];

    }
    //DEBUG_OUTPUT_ARRAY(sum,N+1);
    for(long long int i = N-P; i >= 1; i--){
        if(line-A[i]>M){continue;}
        if(i+P-1>=V){
            res++;
            
            continue;
        }
        long long int ok=(A[i]+M)*(N-P-i+1)-(sum[i+1]-sum[N-P+2]);
        if(ok>=(V-(i+P-1))*M){
            res++;
            //cout<<i<<" "<<ok<<" "<<(V-(i+P-1))*M<<" "<<(sum[i+1]-sum[N-P+2])<<endl;
        }
        
    }
    cout<<res<<endl;
}
