#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a, b;
    vector<int> c = {0,1,2,3};
    cin >> a >> b;
    c.at(a) = 0;
    c.at(b) = 0;
    
    for(auto i : c) {
        if (i != 0) cout << i << endl;
    }
    
}
