#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <stdio.h>
//#include <stack>
//#include <queue>
//#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
//#include <list>
#include <iomanip>
//#include <stdlib.h>
//#include <cctype>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
//#define rep(i, n) for (int i = 0; i < int(n); i++)
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++)
const int MAX_N = 1000000;
const Int MAX_N_Int = 1000000000000;

template <typename T>
void printV(const std::vector<T>& v, const char * const separator = " ")
{
    if(!v.empty())
    {
        std::copy(v.begin(),
                  --v.end(),
                  std::ostream_iterator<T>(std::cout, separator));
        std::cout << v.back() << "\n";
    }
}

int D;
string str,s,u;
vector<int>c(26);
vector<int>t(365);
vector<vector<int>> ss(365, vector<int>(26));
//vector<vector<int>> last(365, vector<int>(26));
vector<int> last(26);
int satisfaction=0;
int score(){
    for (int d = 0; d < D; ++d) {
        int i = t[d]-1;
        satisfaction+=ss[d][i];

        last[i]=d+1;
        for (int cc = 0; cc < 26; ++cc) {
            satisfaction-=c[cc]*((d+1)-last[cc]);
        }
        //printV(last);
        //cout<<i<<" "<<satisfaction<<endl;
        cout<<satisfaction<<endl;
    }

    return satisfaction;
}

int main() {
    IOS;
    prec;

    cin>>D;
    rep(i,0,26)cin>>c[i];
    for (int y = 0; y < D; ++y) {
        for (int x = 0; x < 26; ++x) {
            cin>>ss[y][x];
        }
    }
    rep(i,0,D)cin>>t[i];
    //cout<<score();
    score();









    cout<<endl;
    return 0;
}
