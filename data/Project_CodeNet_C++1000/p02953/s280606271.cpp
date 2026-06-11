#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = n-1; 0 < i; i--){
        if(h[i-1] <= h[i]) continue;
        else if(h[i] + 1 == h[i-1]) h[i-1]--;
        else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}