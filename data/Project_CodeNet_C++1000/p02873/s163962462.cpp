#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> ans(s.length()+1, 0);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<') ans[i+1] = ans[i]+1;
    }
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '>') ans[i] = max(ans[i], ans[i+1]+1);
    }
    long long int fans = 0;
    for(int i = 0; i < ans.size(); i++) fans += ans[i];
    cout << fans << endl;
    return 0;
}