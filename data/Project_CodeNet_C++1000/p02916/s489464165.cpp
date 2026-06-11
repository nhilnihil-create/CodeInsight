#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n, sum=0, front=-1;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i, n)cin >> a[i];
    rep(i, n)cin >> b[i];
    rep(i, n-1)cin >> c[i];
    rep(i, n){
        sum += b[a[i]-1];
        if(a[i] == front+1) sum += c[front-1];
        front = a[i];
    }
    cout << sum << endl;
    return 0;
}