#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    set<char> s;
    
    char a;
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);

    if(s.size() == 2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0; 
}
