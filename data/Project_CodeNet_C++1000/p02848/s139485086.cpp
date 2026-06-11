#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        s[i]= s[i]+n;
        if(s[i] > 'Z'){
            s[i] = s[i]-'Z'+'A'-1;
        }
    }
    cout << s << endl;
}