#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    for(int i=0; i<m; i++) cin >> p[i] >> s[i];
    for(int i=0; i<m; i++) p[i]--;

    vector<int> penalty(n);
    vector<bool> ac(n);
    for(int i=0; i<n; i++) {penalty[i] = 0; ac[i] = false;}

    for(int i=0; i<m; i++){
        if(s[i] == "AC")  ac[p[i]] = true;
        else{
            if(!ac[p[i]]) penalty[p[i]]++;
        }
    }

    int pena = 0, ans = 0;
    for(int i=0; i<n; i++){
        if(ac[i]) {
            ans++;
            pena += penalty[i];
        }
    }

    cout << ans << ' ' << pena << endl;
    return 0;


}