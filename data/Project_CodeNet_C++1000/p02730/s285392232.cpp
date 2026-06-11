#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<char>a(n);
    vector<char>b(n);
    for(int i=0; i<n; i++){
        if(s[i] != s[n-1-i]){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i=0; i<n/2; i++){
        if(n%2==0){
            if(s[i]!=s[n/2-1-i]){
            cout << "No" << endl;
            return 0;
            }
            if(s[n/2+i]!=s[n-1-i]){
                cout << "No" << endl;
                return 0;
            }
        }else{
            if(s[i]!=s[n/2-1-i]){
            cout << "No" << endl;
            return 0;
            }
            if(s[n/2+1+i]!=s[n-1-i]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}