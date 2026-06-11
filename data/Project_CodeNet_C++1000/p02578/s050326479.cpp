#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long temp = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){ 
        long long a;
        cin >> a;
        if(a >= temp) temp = a;
        else ans += temp - a;
    }
    cout << ans << endl;   
}