#include<iostream>
#include<iomanip>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>s[i]>>t[i];

    string tar;
    cin>>tar;
    int res=0;
    for(int i=0;i<n;i++){
        if(tar==s[i]){
            for(int j=i+1;j<n;j++){
                res+=t[j];
            }
            break;
        }
    }
    
    cout<<res<<endl;
    return 0;
}
