#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int a, b;
    cin >> a >> b;
    int c = 0;
    vector<int> data = {1, 2, 3};
    for(int i=0; i<data.size(); i++){
        if(a != data.at(i) && b != data.at(i)){
            c = i+1;
        }
    }
    cout << c << endl;
}