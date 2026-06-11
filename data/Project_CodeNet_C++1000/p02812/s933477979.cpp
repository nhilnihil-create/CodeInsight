#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,m;
    string s, c;
    cin >> n >> s;
    m = 0;
    for(int i = 0; i < n; i++){
        if(i + 1 > n) break;
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C' ){
            m++;
        }
    }

    cout << m << endl;

}