#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    bool check = false;
    for(int i=0;i<3;i++){
        if(n%10 == 7)check = true;
        n/=10;
    }
    cout << ((check)? "Yes": "No") << endl;
    return 0;
}