#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0, n = s.size()/2, size = s.size();
    char a,b;
    for(int i=0; i<n; i++){
        if(s.at(i) != s.at(size-1-i)){
            count++;
        }
    }
    cout << count << endl;
}