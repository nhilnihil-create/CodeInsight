#include <iostream>
#include <algorithm>
using namespace std;

long long n, a, t = 0, m = 0;

int main() {
    cin >> n;
    
    for(long long i = 0; i < n; i++){
        cin >> a;
        
       if(t < a)
           t = a;
       else{
           m += t - a;
       }
    }
    
    cout << m << endl;
}
