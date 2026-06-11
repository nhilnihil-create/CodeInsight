#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isprime(int x){
    if( x==2 ){
        return true;
    }
    if( x<2 ){
        return false;
    }

    for(int i=2; i<=sqrt(x); ++i){
        if( x%i==0 ){
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int x;
    for(int i=0; i<n; ++i){
        cin >> x;
        if( isprime(x) ){
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;

}
