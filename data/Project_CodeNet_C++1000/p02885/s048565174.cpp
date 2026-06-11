#include <bits/stdc++.h>

using namespace std;

int main(){
        int a,b,ans;
        cin >> a >> b;

        if(a <= b * 2){
                cout << "0" << endl;
        }
        else if (a > b * 2){
                cout << a - b * 2 << endl;
        }
        return 0;
}