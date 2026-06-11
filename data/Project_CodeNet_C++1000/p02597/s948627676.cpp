#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    string s;
    cin >> s;
    int left = 0, right = N - 1;
    while(left < right){
        if(s[left] == 'R' && s[right] == 'W'){
            left++;
            right--;
        }
        else if(s[left] == 'R') left++;
        else if(s[right] == 'W') right--;
        else{
            ans++;
            left++;
            right--;
        }
    }
    cout << ans << endl;
    return 0;
}
