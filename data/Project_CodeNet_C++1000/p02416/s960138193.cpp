#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef unsigned long long ull;

int main(){
    string x;
    cin >> x;

    while(x != "0"){
        int S = 0;
        for (int i=0;i<x.size();i++){
            S += (int)x[i] - (int)'0';
        }
        cout << S << endl;
        cin >> x;
    }
    return 0;
}