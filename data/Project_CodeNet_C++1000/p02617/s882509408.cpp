#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>N;

    ll res = 1LL*(N+2)*(N+1)*N/6;
    for (int i=0;i<N-1;i++) {
      int a,b;cin>>a>>b;
      if (a>b) swap(a,b);
      res -= 1LL* a * (N-b+1);
    }
    cout << res << '\n';

    return 0;
}
