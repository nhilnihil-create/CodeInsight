// 154 B

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>

using namespace std;

int main(){
    long long int a, b, n, buf, ans;
    cin >> a >> b >> n;
    buf = min(b-1, n);
    cout << buf*a/b << endl;
    return 0;
}