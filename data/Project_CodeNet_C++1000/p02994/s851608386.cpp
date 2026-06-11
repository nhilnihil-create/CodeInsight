#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N,L;
    cin >> N >> L;
    int sum = 0;
    int e = 1000;
    for(int i=0;i<N;i++){
        int a = L + i;
        sum += a;
        if(abs(e) > abs(a)){
            e = a;
        }
    }
    int ans = sum - e;
    cout << ans << endl;
}
