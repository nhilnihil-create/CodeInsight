#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <numeric>
#define ll long long 
#define wolfe ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define elif else if
using namespace std;
int main () {
    wolfe;
    char a;
    cin >> a;
    if(a>='a' && a<='z') cout << 'a' << endl;
    else cout << 'A' << endl;
    return 0;
}