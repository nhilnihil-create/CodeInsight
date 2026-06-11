#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; string s;
    cin >> n >> s;

    int l[10], r[10];
    fill_n(l, 10, -1);
    fill_n(r, 10, -1);
    for(int i = 0; i < 10; i++){
        string c = to_string(i); 
        if(s.find(c) != string::npos){
            l[i] = s.find(c);
            r[i] = s.rfind(c);
        }
    }

    // p1p2p3 となるような3桁の暗証番号を考えてその数を ans としてカウント
    int ans = 0;
    for(int p1 = 0; p1 < 10; p1++){
        if(l[p1] == -1) continue;

        for(int p3 = 0; p3 < 10; p3++){
            if(r[p3] <= l[p1] + 1) continue;

            string str = s.substr(l[p1]+1, r[p3]-l[p1]-1);
            for(int p2 = 0; p2 < 10; p2++){
                if(str.find(to_string(p2)) != string::npos)
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}