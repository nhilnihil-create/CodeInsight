#include<bits/stdc++.h>

using namespace std;

void func(void){
    int n, k;
    cin >> n >> k;
    int rest = n - k;
    if(k == 1) cout << "0\n";
    else cout << rest << "\n";
}

int main(){
    func();
    return 0;
}
