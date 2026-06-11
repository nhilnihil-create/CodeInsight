#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    rep(i, n){
        int x,y;    cin>>x>>y;
        a[i] = x+y;
        b[i] = x-y;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << max(a[n-1]-a[0], b[n-1]-b[0]) << endl;
}
