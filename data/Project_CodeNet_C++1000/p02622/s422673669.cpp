#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <numeric>
#define ll long long 
#define wolfe ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define elif else if
using namespace std;
int main () {
    wolfe;
    string a,b;
    cin >> a >> b;
    int n = a.size();
    int cnt = 0;
    for(int i=0 ; i<n; i++) {
        if(a[i]!=b[i]) cnt ++;
    }
    cout << cnt << endl;
    return 0;
}