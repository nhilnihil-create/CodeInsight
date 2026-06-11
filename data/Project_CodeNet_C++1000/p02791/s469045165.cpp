#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n ;
    cin >> n;
    int mnn = INT_MAX;
    int count = 0;
    for(int i = 0 ; i < n ;  i++){
        int x ;
        cin >> x;
        if(x <= mnn)count++;
        mnn = min(x , mnn);
    }
    cout << count << endl;
}
