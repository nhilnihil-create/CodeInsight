#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = (int)s.length();
    int count = 0;

    for(int i = 0; i < len/2; i ++){
        if(s[i] != s[len - i - 1]){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}