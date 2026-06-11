#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll n,k,c;
    cin >> n >> k >> c;
    char s[n];
    cin >> s;

    vector<int> dpl,dpr;
    for (int i=0; i<n && dpl.size() < k; i++){
        if(s[i] == 'o'){
            dpl.push_back(i);
            i += c;
        }
    }
    for (int i=n; i>=0 && dpr.size() < k; i--){
        if(s[i] == 'o'){
            dpr.push_back(i);
            i -= c;
        }
    }
    reverse(dpr.begin(),dpr.end());
    for(int i=0;i<k;i++){
        if (dpl[i] == dpr[i]){
            cout << dpl[i]+1 << endl;
        }
    }
    return 0;
}