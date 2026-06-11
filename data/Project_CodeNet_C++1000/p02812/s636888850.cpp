#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for(int i = 0; i <= n-3; i++){
        if(s.substr(i, 3) == "ABC"){
            ans++;
            i += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
