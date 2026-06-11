#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    unsigned long long int a;
    double b;
    cin >> a >> b;
    string bstr;
    bstr = to_string(b);
    bstr.erase(bstr.size()-7, 1);
    bstr.erase(bstr.size()-4, 5);
    // cout << bstr << endl;

    // while(bstr.at(0)==0){
    //     bstr.erase(0, 1);
    // }
    // cout << bstr << endl;

    int b2 = stoi(bstr);
    //cout << b2 << endl;
    unsigned long long int ans = a*b2/100;
    cout << ans << endl;
}