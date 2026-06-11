#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    int n,ans = -1;
    cin >> n;
    for(float i=1;i<=n;i++){
        if(int(i * 1.08) == n){
            ans = i;
        }
    }
    if(ans != -1){
        cout << ans << endl;
    }else{
        cout << ":(" << endl;
    }
    return 0;
}