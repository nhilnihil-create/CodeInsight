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

int main(){
    std::ios::sync_with_stdio(false);
    int x, n;
    cin >> x >> n;
    set<int> p;
    for(int i=0;i<n;++i)
    {
      int tmp;
      cin >> tmp;
      p.insert(tmp);
    }

    int min_dist = 1 << 30;
    int ret = 0;
    for(int i=0;i<=101;++i)
    {
      if(p.find(i) == p.end()){
        if(abs(x - i) < min_dist)
        {
          min_dist = abs(x - i);
          ret = i;
        }
      }
    }
    cout << ret << endl;
}