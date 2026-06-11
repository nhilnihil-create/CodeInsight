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
    map<int,int> m;
    int N;cin>>N;
    if(N<3){
        cout << 0 << endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        int l;cin>>l;
        m[l]++;
    }
    vector<int> L;
    for(auto i=m.begin();i!=m.end();++i){
        if(i->second) L.push_back(i->first);
    }
    sort(L.begin(),L.end());
    int ans = 0;
    for(int i=0;i<L.size();i++){
        for(int j=i+1;j<L.size();j++){
            for(int k=j+1;k<L.size();k++){
                if(L[i]+L[j]>L[k]) ans += m[L[i]]*m[L[j]]*m[L[k]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}