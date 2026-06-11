#include <bits/stdc++.h>
using namespace std;
int main(){
    int K;
    cin >> K;
    vector<int> md(K);
    md.at(0) = 7%K;
    for(int i=1;i<K;i++){
        
        md.at(i) = (md.at(i-1)*10+7)%K;
    }
    auto result = find(md.begin(),md.end(),0);
    if(result == md.end()) cout << -1 << endl;
    else cout << distance(md.begin(),result)+1 << endl;
}