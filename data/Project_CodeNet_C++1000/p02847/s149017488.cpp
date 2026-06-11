#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<string> vs = {
        "SUN","MON","TUE","WED","THU","FRI","SAT" 
    };

    auto itr = std::find(vs.begin(), vs.end(), s);
    int index = std::distance(vs.begin(), itr);
    println((7 - index));
    return 0;
}