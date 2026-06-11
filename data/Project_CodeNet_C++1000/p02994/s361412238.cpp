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
    int N,L;cin>>N>>L;
    int _min = 1e9;
    int ans = 0;
    for(int i=0;i<N;i++){
        ans += L + i;
        if(abs(L+i)<_min) _min = abs(L + i);
    }
    cout << (L >= 0 ? ans - _min : ans + _min) << endl;
    return 0;
}