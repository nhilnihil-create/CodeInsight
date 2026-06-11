#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    string wlist[] = {"Sunny","Cloudy","Rainy","Sunny"};
    string *s = wlist;
    string str; cin >> str;
    while(*s!=str)s++;
    cout << *(s+1) << endl;
}