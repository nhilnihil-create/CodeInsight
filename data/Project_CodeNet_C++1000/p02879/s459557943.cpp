#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

int main (){
    int a,b;
    cin >> a >> b;
    if (a > 9 || b > 9){
        cout << "-1" << endl;
    }else cout << a*b << endl;
    return 0;
}