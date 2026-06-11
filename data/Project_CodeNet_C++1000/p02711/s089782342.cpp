#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int hPlace = n / 100;
    int tPlace = (n / 10) % 10;
    int oPlace = n % 10;

    if(hPlace == 7  || tPlace == 7 || oPlace == 7) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }

}