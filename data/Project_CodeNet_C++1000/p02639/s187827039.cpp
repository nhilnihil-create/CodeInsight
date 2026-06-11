#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> x(5);
    int i, ans;
    for(i=0;i<5;i++){
        cin >> x.at(i);
        if(x.at(i) == 0)
            ans = i + 1;
    }

    cout << ans << endl;
}