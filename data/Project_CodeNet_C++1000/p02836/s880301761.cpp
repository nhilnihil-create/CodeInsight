#include <bits/stdc++.h>
using namespace std;

string s;
int res = 0;
int main(){
    cin >> s;
    int i = 0,j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]) {res += 1;i++;j--;}
        else{
            i++;
            j--;
        }
    }
    cout << res << endl;
    return 0;
}