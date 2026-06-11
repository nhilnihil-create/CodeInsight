#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    ll A,B,C,D;cin>>A>>B>>C>>D;
    ll A_C = (A - 1) / C;
    ll A_D = (A - 1) / D;
    ll B_C = B / C;
    ll B_D = B / D;
    ll A_CD = (A - 1) / (C * D / __gcd(C,D));
    ll B_CD = B / (C * D / __gcd(C,D));
    cout << B + 1 - A - ((B_C - A_C) + (B_D - A_D) - (B_CD - A_CD)) << endl;
    return 0;
}