#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1234567;
int a[123][123];


int main() {
    long long x;
    cin>>x;
    for (int i=-1000;i<=1000;i++)
    for (int j=-1000;j<=1000;j++) {
        long long a=1ll*i*i*i*i*i;
        long long b=1ll*j*j*j*j*j;
        if (a-b==x) {
            cout<<i<<" "<<j;
            return 0;
        }
    }
    return 0;
}
