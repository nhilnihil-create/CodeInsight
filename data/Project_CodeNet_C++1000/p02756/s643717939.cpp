#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
    string s;
    deque<string> ss;
    int q;
    cin >> s;
    cin >> q;
    ss.push_front(s);
    int flag = 1;//flagが-1の時は後ろから1の時は前から
    for(int i = 0;i < q;i++){
        int t;
        cin >> t;
        switch(t){
            case 1:
               flag *= (-1);
               break;
            case 2:
                int f;
                string c;
                cin >> f >> c;
                switch(f){
                    case 1:
                        switch(flag){
                            case 1:
                                ss.push_front(c);
                                break;
                            case -1:
                                ss.push_back(c);
                                break;
                        }
                        break;
                    case 2:
                        switch(flag){
                            case 1:
                                ss.push_back(c);
                                break;
                            case -1:
                                ss.push_front(c);
                                break;
                        }
                        break;
                }
        }
    }
    string ans = "";
    for(auto i:ss){
        ans += i;
    }
    switch(flag){
        case 1:
            cout << ans;
            break;
        case -1:
            reverse(ans.begin(),ans.end());
            cout << ans;
            break;
    }
    return 0;
}
