#include <iostream>

using namespace std;
bool is_pal(string s, int l, int r){
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++, r--;
    }
    return true;
}
int main(){
    std::string S;
    cin >> S;
    int l = S.size();
    // int mid = (l-1)/2;
    bool yes = true;
    // for (int i=0;i<mid;i++){
    //     if ((S.at(i) == S.at(l-1-i)) && (S.at(i) == S.at(mid-i-1))) continue;
    //     else {
    //         yes = false;
    //         break;
    //     }
    // }
    yes = is_pal(S, 0, l-1) * is_pal(S, 0, (l-3)/2) * is_pal(S, (l+1)/2, l-1);
    if (yes) cout << "Yes";
    else cout << "No";
}