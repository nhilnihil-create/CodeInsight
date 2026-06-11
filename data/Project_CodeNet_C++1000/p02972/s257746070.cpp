#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
typedef long long ll;
const int maxn = 234567;
int a[maxn], v[maxn];
int main(){
     int n; cin >> n;
    
     for(int i = 1; i <= n; i++) cin >> a[i];
     vector<int> good;
     for(int i = n; i >= 1; i--){
         int sum = 0;
         for(int j = i + i; j <= n; j += i) sum ^= v[j];
         v[i] = sum ^ a[i];
         if(v[i]) good.push_back(i);
     }
     cout << good.size() << endl;
     for(int v : good) cout << v << " ";
     cout << endl;
    return 0;
}
