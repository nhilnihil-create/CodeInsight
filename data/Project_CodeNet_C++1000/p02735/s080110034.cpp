
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

long long int H,W,N,C,K,B[200020],res[200][200]={},mymin[200],mymax[200],now=INF,t=0,bus=0;
string S[102];
deque<pll>deq;
int main(){
    cout << fixed << setprecision(18);
    cin>>H>>W;
    for(long long int i = 0; i < H; i++){
        cin>>S[i];
        for(long long int j = 0; j < W; j++){
            res[i][j]=INF;
        }
    }
    
    if(S[0][0]=='#'){res[0][0]=1;}
    else{res[0][0]=0;}
    deq.push_front({0,0});
    while(!deq.empty()){
        pll tmp=deq.front();
        deq.pop_front();
        if(tmp.first==H-1&&tmp.second==W-1){cout<<res[H-1][W-1]<<endl;return 0;}
        if(tmp.first<H-1){
            if(S[tmp.first+1][tmp.second]=='.'){
                if(res[tmp.first+1][tmp.second]>res[tmp.first][tmp.second]){deq.push_front({tmp.first+1,tmp.second});
                res[tmp.first+1][tmp.second]=res[tmp.first][tmp.second];}
                
            }else if(S[tmp.first][tmp.second]=='.'&&S[tmp.first+1][tmp.second]=='#'){
                if(res[tmp.first+1][tmp.second]>res[tmp.first][tmp.second]+1){deq.push_back({tmp.first+1,tmp.second});
                res[tmp.first+1][tmp.second]=res[tmp.first][tmp.second]+1;}
                
            }else{
                if(res[tmp.first+1][tmp.second]>res[tmp.first][tmp.second]){deq.push_front({tmp.first+1,tmp.second});
                res[tmp.first+1][tmp.second]=res[tmp.first][tmp.second];}
               
            }
        }

        if(tmp.second<W-1){
            if(S[tmp.first][tmp.second+1]=='.'){
                if(res[tmp.first][tmp.second+1]>res[tmp.first][tmp.second]){deq.push_front({tmp.first,tmp.second+1});
                res[tmp.first][tmp.second+1]=res[tmp.first][tmp.second];}
                
            }else if(S[tmp.first][tmp.second]=='.'&&S[tmp.first][tmp.second+1]=='#'){
                if(res[tmp.first][tmp.second+1]>res[tmp.first][tmp.second]+1){deq.push_back({tmp.first,tmp.second+1});
                res[tmp.first][tmp.second+1]=res[tmp.first][tmp.second]+1;}
                
            }else{
                if(res[tmp.first][tmp.second+1]>res[tmp.first][tmp.second]){deq.push_front({tmp.first,tmp.second+1});
                res[tmp.first][tmp.second+1]=res[tmp.first][tmp.second];}
                
            }
        }
    }
    
}

