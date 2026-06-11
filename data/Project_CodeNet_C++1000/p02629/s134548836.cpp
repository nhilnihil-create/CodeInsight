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
    ll N;cin>>N;
    vector<int> digit;
    int mod;
    N--;
    while(N>=0){
        mod = N % 26;
        N = N / 26 - 1;
        digit.push_back(mod);
    }
    reverse(digit.begin(),digit.end());
    for(auto i=digit.begin();i!=digit.end();++i){
        cout << (char)('a' + *i);
    }
    cout << endl;
    return 0;
}