#include <bits/stdc++.h>
using namespace std;

int count(string a, string b){
    int count = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i]!=b[i]) count++;
    }
    return count;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << count(a,b);
    return 0;
}