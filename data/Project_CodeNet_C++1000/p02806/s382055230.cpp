#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s[55];
    int t[55];
    int result = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i];
    }
    string x;
    cin >> x;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == x)
          break;
            result += t[i];
    }
    cout << result << endl;
}
