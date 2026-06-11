#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<numeric>

using namespace std;

int main(){
    int a;
    string s ,st;
    cin >> a;
    cin >> s >> st;
    for(int i = 0; i < a; i++){
        cout << s[i] << st[i];
    }

}