#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 1;
    char past = s[0];
    for(int i = 1; i < n; i++){
        if(past != s[i]){
            past = s[i];
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}