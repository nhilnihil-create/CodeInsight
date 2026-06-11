#include <iostream>
using namespace std;

int main(){
    int n;cin >> n;
    int max = 0;
    long long ans = 0;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        if(max < tmp) {
            max = tmp;
        } else {
            ans += max-tmp;
        }
    }
    cout << ans << endl;
}