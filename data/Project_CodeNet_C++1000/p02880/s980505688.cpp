#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(){
    IOS;
    int n;
    cin >> n;
    for(int i=1;i<10;i++){
        if(n/i < 10 && !(n - (n/i)*i)){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}