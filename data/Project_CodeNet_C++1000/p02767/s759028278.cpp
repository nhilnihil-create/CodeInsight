#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    vector<int> tairyoku(0);
    for(int i=1;i<=100;i++){
        int tai = 0;
        for(int j=0;j<n;j++){
            tai += (array.at(j) - i) * (array.at(j) -i);
        }
        tairyoku.push_back(tai);
    }
    int min = 10000000;
    for(int i=0;i<tairyoku.size();i++){
        if(min > tairyoku.at(i)) min = tairyoku.at(i);
    }
    cout << min << endl;
}