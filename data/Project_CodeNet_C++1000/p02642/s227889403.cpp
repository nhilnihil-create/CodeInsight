#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

bool dividable[1000001];
bool counted[1000001];

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n] = {};
    for(int i=0;i<n;++i)
    {
      cin >> a[i];
    }

    sort(a, a+n);
    int ret = 0;
    for(int i=0;i<n;++i)
    {
      if(dividable[a[i]])
      {
        counted[a[i]] = false;
        continue;
      }

      counted[a[i]] = true;
      for(int j=1;a[i]*j < 1000001;++j){
        dividable[a[i]*j] = true;
      }
    }
    cout << accumulate(counted, counted + 1000001, 0) << endl;
}