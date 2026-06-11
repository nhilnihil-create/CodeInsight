#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, i;
    double c=0;
    cin >> n;
    for(i=1; i<=n; i++){
        if(i%2!=0){
            ++c;
        }
    }
    cout << fixed << setprecision(10) << c/n << endl;
    
    
    
    
    
	return 0;
}