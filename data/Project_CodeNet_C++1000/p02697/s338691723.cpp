#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;

    if(N%2==0){
        int a = N/2;
        int b = a+1;
        for(int i=0; i<M; i++){
            cout << a << " " << b << "\n";
            a--; b++;
            if(a == (N-1)/4+1) b++;
        }
    }else{
        int a = N/2;
        int b = a+1;
        for(int i=0; i<M; i++){
            cout << a << " " << b << "\n";
            a--; b++;
        }
    }
}