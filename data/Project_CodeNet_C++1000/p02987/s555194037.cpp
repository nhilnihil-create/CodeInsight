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
    map<char,int> m;
    string s;cin>>s;
    for(int i=0;i<4;i++) m[s[i]]++;
    if(m.size()!=2||m[s[0]!=2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}