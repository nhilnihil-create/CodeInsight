#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    string ttr;
    cin >> str;
    cin >> ttr;
    int n;
    n = str.size();
    for(int i=0; i<n; i++){
        if(str[i] != ttr[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

