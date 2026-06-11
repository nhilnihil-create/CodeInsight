#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    // 2乗の和と和
    int sum2=0,sum=0;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i< N; i++) {
        cin >> a.at(i);
        sum2 += a.at(i)*a.at(i);
        sum += a.at(i);
    }
    int p = floor((double)sum/N);
    if((double)sum/N-p > 0.5) p++;
    cout << sum2+p*p*N-2*p*sum << endl;
    return 0;
}
