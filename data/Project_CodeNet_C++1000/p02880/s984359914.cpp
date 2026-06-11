#include<iostream>
using namespace std;

int a, i;
bool ada = false;

int main () {
    cin>>a;
    for (i=1; i<=a; i++) {
        if (a%i==0) {
            if (i<=9 && a/i<=9) {
                ada = true;
            }
        }
    } if (ada) {cout<<"Yes"<<endl;}
    else {cout<<"No"<<endl;}
}