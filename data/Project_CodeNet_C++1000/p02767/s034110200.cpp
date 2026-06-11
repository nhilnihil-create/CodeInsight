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
    cout << sum2+min(p*p*N-2*p*sum,(p+1)*(p+1)*N-2*(p+1)*sum) << endl;
    return 0;
}
