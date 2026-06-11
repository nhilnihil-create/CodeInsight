#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    vector<int> hon{2,4,5,7,9};
    vector<int> pon{0,1,6,8};

    
    if (find(hon.begin(), hon.end(), (int)(s[s.size()-1]) - '0') != hon.end()){
        cout << "hon" << endl;
    } else if (find(pon.begin(), pon.end(), (int)(s[s.size()-1]) - '0') != pon.end()){
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }
    return 0;
}