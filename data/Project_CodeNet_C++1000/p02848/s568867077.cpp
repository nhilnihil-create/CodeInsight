#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
            s[i] = s[i] + n;
            if(s[i]>'Z'){
                s[i] = 64 + (s[i]-'Z');
            }
    }
    cout << s << endl;
    return 0;
}

