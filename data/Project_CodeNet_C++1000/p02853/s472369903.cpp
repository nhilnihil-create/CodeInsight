#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    vector<int> shokin(206);
    shokin.at(1)=300000;
    shokin.at(2)=200000;
    shokin.at(3)=100000;
    if(x==1&&y==1){
        cout << shokin.at(1)*2+400000 << endl;
    }else{
        cout << shokin.at(x)+shokin.at(y) << endl;
    }
}