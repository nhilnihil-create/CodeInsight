#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for(int i=0; i<n-2; i++)
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') cnt++;
    cout << cnt << '\n';
    return 0;
}