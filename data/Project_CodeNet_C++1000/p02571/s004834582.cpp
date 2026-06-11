#include <bits/stdc++.h>
using namespace std;;
 
int main(){
	
    string s, t;
    int sSize, tSize, ans, count;
    
    cin >> s >> t;
    
    sSize = s.size();
    tSize = t.size();
    
    ans = tSize;
    
    for (int i = 0; i <= sSize-tSize; i++){
        count = 0;
        for (int j = 0; j < tSize; j++){
            if (s[i + j] != t[j]){
                count++;
            }
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}
