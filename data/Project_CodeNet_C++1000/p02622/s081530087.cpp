#include<bits/stdc++.h>
using namespace std;

int hs[200000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    int l = s1.size();
    for(int i = 0; i < l; i++){
        if(s1[i] - s2[i] != 0){
            hs[i] = 2;
        }
    }
    cout << count(hs, hs + l, 2);
    return 0;
}