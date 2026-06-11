#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ string a, b; int ans = 0;
    cin >> a >> b;
    for (int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}