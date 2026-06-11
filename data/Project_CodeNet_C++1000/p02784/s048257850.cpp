#include <iostream>
using namespace std;
int main() {
    int n, t, a;
    cin >> n >> a;
    int tot = 0;
    for(int i = 0; i < a; ++i) {
        cin >> t;
        tot += t;
    }
    if(tot >= n) 
    	cout<<"Yes";
    else 
    	cout<<"No";
 
    return 0;
}
