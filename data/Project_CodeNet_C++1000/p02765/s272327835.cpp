#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,r;
    cin >> n >> r;
    if(n < 10){
        cout << 100*(10 - n) + r << endl;
    }
    else{
        cout << r <<endl;
    }
}
