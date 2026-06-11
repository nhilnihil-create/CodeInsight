#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

int main (){
    int x,k;
    cin >> k >> x;
    int money = 500 * k;
    if (x <= money){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
    return 0;
}
    
