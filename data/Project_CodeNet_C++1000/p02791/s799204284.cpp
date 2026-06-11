#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    int bt = n+1;
    for(int i = 0; i < n; i++){
        if(a[i] < bt){
            ans++;
            bt = a[i];
        }
    }

    cout << ans << endl;

    return 0;
}