#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    for (int i = 0; i< s.size(); i++){
        s[i] += k;
        if (s[i] > 'Z'){
            s[i] = 64 + (s[i] - 'Z');
        }
    }
    cout<<s;
    return 0;
}
