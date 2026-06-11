#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string data[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string s;cin >> s;
    for(int i=0;i<7;i++) if(data[i]==s) cout << 7-i << endl;
}