#include <bits/stdc++.h>
using namespace std;
int main(void){

    int chi, candy;
    cin >> chi >> candy ;
    
    set<int> have;
    
    int num, tmp;
    for(int i = 0; i < candy; i++){
        cin >> num ;
        for(int j = 0; j < num ; j++){
            cin >> tmp ;
            have.insert(tmp);
        }
    }
    
    cout << chi - have.size() << endl;
    
}
