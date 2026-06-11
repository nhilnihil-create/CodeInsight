#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    while(m--){
        int x;
        cin >> x;
        n -= x;
    }
    if(n < 0){
        cout << "-1" << endl;
    }else{
        cout << n << endl;
    }

}