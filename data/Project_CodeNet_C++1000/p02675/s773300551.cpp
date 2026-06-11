#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string str, ans = "hon";
    cin >> str;
    int s =str.size() - 1;
    if(str.at(s) == '3') ans ="bon";
    if(str.at(s) == '0' || str.at(s) == '1' || str.at(s) == '6' || str.at(s) == '8') ans ="pon";
    cout << ans << endl;
}