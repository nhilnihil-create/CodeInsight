#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


const int MAX = 150001;  
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        if (i%2==1 && x%2==1) ans++;
    }
    cout << ans;
       
}