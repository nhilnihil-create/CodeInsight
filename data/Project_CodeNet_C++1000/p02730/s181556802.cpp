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
        a[i]=s[i];
        b[i]=s[n-1-i];
    }

    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    reverse(a.begin(),a.begin()+n/2);

    for(int i=0; i<n/2; i++){
        if(a[i]!=b[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}