#include <iostream>
#include <set>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    int sum = 1;
    for(int i =0 ;i<n -1;i++){
        if(s[i] != s[i+1])sum++;
    }
    cout << sum << endl;
}