#include <bits/stdc++.h>
using namespace std;

    int main() {
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int k = s.length();
        
        if(n>=k)
            cout << s;
        else{
            
            for(int i=0; i<n; i++){
                cout << s.at(i);
            }
            cout <<"...";
        }
            
        return 0;
        }