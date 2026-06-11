#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s1, s2;
    long long len, cnt=0;
    cin >> s1 >> s2;
    len = s1.length();
    for(int i=0; i<len; i++){
        if(s1[i] != s2[i]) ++cnt;
    }
    if(cnt>0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    
    
	return 0;
}