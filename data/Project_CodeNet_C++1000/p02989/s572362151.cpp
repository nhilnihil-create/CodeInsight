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
    int N;cin>>N;
    vector<int> d(N);
    map<int,int> m;
    for(int i=0;i<N;i++){
        cin >> d[i];
        m[d[i]]++;
    }
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    int sum = 0;
    int p = d.size()-1;
    int ans = 0;
    for(int i=d[p];i>0&&sum<=N/2;i--){
        if(i==d[p]){
            sum += m[d[p]];
            p--;
        }
        if(sum==N/2) ans++;
    }
    cout << ans << endl;
    return 0;
}