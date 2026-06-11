#include <iostream>

#include <cstring>
#include <vector>
#include <string>
using namespace std;
const int inf = 0x3f3f3f3f;


int n, k , c;




int main(){
    //freopen("in.txt", "r", stdin);
    cin>>n>>k>>c;
    string str;
    cin>>str;
    int last = -inf;
    vector<int> L;
    vector<int> R;

    for(int i = 0; i< n; i++){
        if(str[i]=='x') continue;
        if(last + c < i) L.push_back(i), last = i;
    }
    last = inf;
    for(int i = n-1; i>=0; i--){
        if(str[i]=='x') continue;
        if(last - c > i) R.push_back(i), last = i;
    }

    int len = max(L.size(), R.size());
    vector<int>ans;
    for(int i = 0 ; i< len; ++i){
        if(L[i]==R[len -1  - i]) ans.push_back(L[i]);
    }

    if(ans.size()<=k)
    for(int i = 0; i< ans.size() ; i++){
        cout<< ans[i]+1<<"\n";
    }






    return 0;
}