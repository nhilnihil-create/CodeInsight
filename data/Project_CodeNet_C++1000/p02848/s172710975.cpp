#include<iostream>

using namespace std;
int main(){ 
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
       s[i]+=n;
       if(s[i]>'Z')
         s[i] -= 'Z'-'A'+1;
    }
    cout << s;
    cout << endl;
    return 0;
}