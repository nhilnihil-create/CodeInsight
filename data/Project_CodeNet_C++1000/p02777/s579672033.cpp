#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;

    if(s == u){
        cout << a-1 << " " << b << endl;
    }else{
        cout << a << " " << b-1 << endl;
    }
    return 0;
}
