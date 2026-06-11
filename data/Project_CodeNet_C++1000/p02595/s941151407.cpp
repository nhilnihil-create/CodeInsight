// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    int n, d, buf_1, buf_2, count=0;
    cin >> n >> d;
    for(int i=0; i<n; i++){
        cin >> buf_1 >> buf_2;
        if(double(sqrt(pow(buf_1, 2)+pow(buf_2, 2))) <= d) count++;
    }
    cout << count << endl;
    return 0;
}
