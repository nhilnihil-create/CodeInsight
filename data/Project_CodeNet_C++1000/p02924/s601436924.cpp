#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    ll N;
    cin >> N;
    
    ll sum = (1+N)*N/2;
   
    cout << sum-N << endl;
   
    return 0;
}
