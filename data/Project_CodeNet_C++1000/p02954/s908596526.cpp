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

long long int A[5],B,C,N,K,res[200200]={},tmp=0;
pll ba[200200];
string S;

int main(){
    cout << fixed << setprecision(18);
    cin>>S;
    long long int R=1,L=0,type=0,tmp;
    S+='R';
    for(long long int i = 1; i < S.size(); i++){
        if(type==0){
            if(S[i]=='R'){
                R++;
            }else{
                if(R%2==0){
                    res[i]+=R/2;
                    res[i-1]+=R/2;
                }else{
                    res[i]+=R/2;
                    res[i-1]+=R/2+1;
                }
                L=1;
                R=1;
                type=1;
                tmp=i;
            }
        }else{
            if(S[i]=='L'){
                L++;
            }else{
                if(L%2==0){
                    res[tmp]+=L/2;
                    res[tmp-1]+=L/2;
                }else{
                    res[tmp]+=L/2+1;
                    res[tmp-1]+=L/2;
                }

                L=1;
                R=1;
                type=0;
            }
        }
    }
    for(long long int i = 0; i < S.size()-1; i++){
        cout<<res[i]<<" ";
    }
}


