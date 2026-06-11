#include <iostream>
using namespace std;

int main(){
    char s[10001],*c=s;
    int n;
    cin >> n >> s;
    while (*c != '\0') {
        *c = (*c)+n;
        if(*c > 'Z') *c -= 26;
        c++;
    }
    cout << s << endl;
}