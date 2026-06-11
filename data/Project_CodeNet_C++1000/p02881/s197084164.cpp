#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(){
    IOS;
    lln n;
    cin >> n;
    lln mi = INT64_MAX;
    for(lln i=1;i*i<=n;i++){
        if(n % i == 0){
            mi = min(n/i-1 + i-1,mi);
        }
    }
    cout << mi << endl;
    return 0;
}