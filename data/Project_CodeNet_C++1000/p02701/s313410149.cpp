#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> kuji_map;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        if(kuji_map.count(str)){
            continue;
        }else{
            kuji_map[str] = 1;
        }
    }

    cout << kuji_map.size() << endl;
}