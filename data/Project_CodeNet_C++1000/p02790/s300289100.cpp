#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    string a, b, A = "", B = "";
    cin >> a >> b;
    for(int i = 0; i < stoi(b); ++i) A += a;
    for(int i = 0; i < stoi(a); ++i) B += b;
    string ans = min(A, B);
    cout << ans << endl;
    return 0;
}