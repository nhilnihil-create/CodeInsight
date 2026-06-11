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
    int a,b;
    cin >> a >> b;

    int ans = 0;
    if(a > b){
        for(int i = 1; i <= pow(10,a-1); i*=10){
            ans += b*i;
        }
    } else {
        for(int i = 1; i <= pow(10,b-1); i*=10){
            ans += a*i;
        }
    }

    cout << ans << endl;

    return 0;
}