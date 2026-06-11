#include <iostream>

int main(){
    using namespace std;
    std::string S;
    cin >> S;
    int l = S.size();
    int mid = (l-1)/2;
    bool yes = true;
    for (int i=0;i<mid;i++){
        if ((S.at(i) == S.at(l-1-i)) && (S.at(i) == S.at(mid-i-1))) continue;
        else {
            yes = false;
            break;
        }
    }
    if (yes) cout << "Yes";
    else cout << "No";
}