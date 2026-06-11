#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    long long N,A,B;
    cin >> N >> A >> B;
    
    if(A%2!=B%2)cout << min(A-1,N-B)+1+(B-A-1)/2 <<endl;
    else cout << abs(A-B)/2 <<endl;
}
    
    

