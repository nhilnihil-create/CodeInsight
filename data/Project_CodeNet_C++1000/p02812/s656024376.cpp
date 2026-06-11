#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;

int main(){
    int b;
    cin >> b;
    string a;
    cin.ignore();
    cin >> a;
    int count = 0;
    for(int i= 0;i<b-2;i++){
        if(a.substr(i,3)=="ABC")
            count++;

    }
cout << count;

    return 0;
}






