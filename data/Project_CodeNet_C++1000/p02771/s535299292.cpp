#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b[3];
    set<int> d;

    for(int i = 0;i < 3;++i){
        cin >> a;
        d.insert(a);
    }

    if(d.size() == 2)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}