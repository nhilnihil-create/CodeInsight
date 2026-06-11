#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    int n; cin>>n;
    vector<char> s(n);
    int firstw = 1e9;
    int wcnt = 0;
    for(int i = 0; i < n; i++){
        cin>>s[i];
        if(s[i] == 'W'){
            wcnt++;
            if(firstw == 1e9)
                firstw = i;
        }
    }
    if(firstw == 1e9){
        cout<<0<<endl;
        return 0;
    }
    int pos = 0;
    for(int i = 0; i < wcnt; i++){
        if(s[n - i - 1] == 'R') pos++;
    }
    cout<<min({n - firstw - wcnt, wcnt, pos});
}
