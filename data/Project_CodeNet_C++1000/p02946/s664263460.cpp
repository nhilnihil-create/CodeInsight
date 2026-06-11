#include<bits/stdc++.h>
using namespace std;

int main(){
    int bl, conf;
    cin >> bl >> conf;
    vector<int> stone;
    stone.push_back(conf);

    for(int i=1; i<bl; i++){
        stone.push_back(conf - i);
    }
    for(int i=1; i<bl; i++){
        stone.push_back(conf + i);
    }
    sort(stone.begin(), stone.end());
    for(int i=0; i<stone.size(); i++){
        cout << stone.at(i) << " ";
    }
    return 0;
}