#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string s1 = "", s2 = "";
    for(int i = 0; i < a; ++i){
        s2 += to_string(b);
    }
   for(int i = 0; i < b; ++i){
        s1 += to_string(a);
    }
    if(s1 <= s2){
        cout << s1 << endl;
    }
    else{
        cout << s2 << endl;
    }
}
