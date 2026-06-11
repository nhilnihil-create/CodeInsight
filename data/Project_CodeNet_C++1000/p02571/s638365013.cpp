#include <iostream>
#include <string>
using namespace std;

string a, b;
int ans = -1;

int main() {
    cin >> a >> b;
    for(int start  = 0; start+b.length() <= a.length(); start++) {
        int changes = 0;
        for(int i = 0; i < b.length(); i++)
            if(b[i] != a[start+i])
                changes++;
        if(ans == -1 || changes < ans)
            ans = changes;

    }
    cout << ans;

}
