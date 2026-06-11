#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    map<int, string> mp;
    int z;
    string s;
    int countin=0;
    int ca = 0;
    int arr[100000];
    for(int i = 0; i < 100000; i++) {
        arr[i] = 0;
    }


    for(int i = 0; i < m; i++) {
        cin >> z;
        cin >> s;
        mp[z] = s;
        if(mp[z]=="AC" && arr[z] != -1){
            countin += arr[z];
            arr[z] = -1;
            ca++;
        }else if (arr[z] != -1){
            arr[z]++;
        }
    }
    cout << ca << " " << countin << endl;

    /*if(m == 0) {
        cout << 0 << " " << 0 << endl;
    }else{
        cin >> z;
        cin >> s;
        mp.insert(pair<int,string>(z, s));
        if(mp[z] == "AC") {
            ca++;

        }else {
            countin++;
        }
        for(int i = 1; i < m; i++) {
            cin >> z;
            cin >> s;
            if(mp[z]=="AC"){
                b = true;
            }else{
                mp[z] = s;
            }


            if(mp[z]=="AC" && !b) {
                ca++;

            }else if (!b){
                arr[z]++;
                countin ++;
            }
            b = false;
        }
        cout << ca << " " << countin << endl;
    }*/


    return 0;
}