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
    int n,m;
    cin >> n >> m;

    int a = 1, b = m;
    if(m%2 == 0) b++;
    for (int i = 0; i < m/2; i++)
    {
        cout << a++ << " " << b-- << endl;
    }

    a = m+1, b = a+m;
    if(m%2 == 0) a++;
    for (int i = 0; i < (m+1)/2; i++)
    {
        cout << a++ << " " << b-- << endl;
    }
    


    return 0;
}