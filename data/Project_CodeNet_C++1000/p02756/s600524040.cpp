#include <bits/stdc++.h>
using namespace std;

int main(void){
        string s, left = "", right = "";
        int q, count = 0;
        cin >> s >> q;
        for(int i = 0; i < q; i++){
                int query;
                cin >> query;
                if(query == 1){
                        count++;
                } else {
                        int f;
                        string c;
                        cin >> f >> c;
                        if(count % 2 == 0){
                                if(f == 1){
                                        left = left + c;
                                } else {
                                        right = right + c;
                                }
                        } else {
                                if(f == 1){
                                        right = right + c;
                                } else {
                                        left = left + c;
                                }
                        }
                }
        }
        reverse(left.begin(), left.end());
        string ans = left + s + right;
        if(count % 2 == 1){
                reverse(ans.begin(), ans.end());
        }
        cout << ans << endl;
        return 0;
}
