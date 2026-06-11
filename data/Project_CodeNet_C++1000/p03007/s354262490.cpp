
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

long long int N,M,X,H,W,T,A[200200],y[200200],res=0,sum=0,fin=0,cou=0;
string S[105];
map<string,bool>mp;
vector<pll>vec;
vector<long long int>pl,mi;

int main(){
    cout << fixed << setprecision(18);
    cin>>M;
    for(long long int i = 0; i < M; i++){
        cin>>A[i];
        if(A[i]>=0){
            pl.push_back(A[i]);
        }else{
            mi.push_back(A[i]);
        }
    }
    sort(pl.begin(),pl.end());
    sort(mi.begin(),mi.end());
    if(mi.size()>0&&pl.size()>0){
        sum=mi[0];
        for(long long int i = 1; i < pl.size(); i++){
            vec.push_back({sum,pl[i]});
            sum-=pl[i];
        }
        vec.push_back({pl[0],sum});
        sum=pl[0]-sum;
        for(long long int i = 1; i < mi.size(); i++){
            vec.push_back({sum,mi[i]});
            sum-=mi[i];
        }
        cout<<sum<<endl;
        for(long long int i = 0; i < M-1; i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }else if(pl.size()>0){
        sum=pl[0];
        for(long long int i = 1; i < pl.size()-1; i++){
            vec.push_back({sum,pl[i]});
            sum-=pl[i];
        }
        vec.push_back({pl[pl.size()-1],sum});
        sum=pl[pl.size()-1]-sum;
        cout<<sum<<endl;
        for(long long int i = 0; i < M-1; i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }else {
        sum=mi[mi.size()-1];
        for(long long int i = 0; i < mi.size()-1; i++){
            vec.push_back({sum,mi[i]});
            sum-=mi[i];
        }
        
        cout<<sum<<endl;
        for(long long int i = 0; i < M-1; i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }

}

