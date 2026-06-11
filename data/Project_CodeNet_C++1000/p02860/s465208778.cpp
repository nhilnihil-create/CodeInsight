#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    string res="Yes";
    int l;
    cin >> l;
    cin >> s;
    l = s.size();
    if(l%2 ==1){
        res = "No";
    }else{
        for(int i=0 ; i< (int)l/2; i++){
            if(s[i] != s[(int)l/2+i]){
                res = "No";
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}