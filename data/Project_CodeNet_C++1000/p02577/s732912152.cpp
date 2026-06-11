#include <iostream>
using namespace std;

int main(){
    char str[200003]; cin >> str;
    int t=0;
    char *c = str;
    while(*c!='\0'){
        t += *c-'0';
        t %= 9;
        c++;
    }
    if(t){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}