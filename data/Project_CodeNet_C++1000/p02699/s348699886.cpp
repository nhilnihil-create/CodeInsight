#include <bits/stdc++.h>

using namespace std;

int main(){
        int s,w;
        cin >> s >> w;

        if (w >= s){
                cout << "unsafe" << endl;
        }
        else if(w < s){
                cout << "safe" << endl;
        }
        return 0;
}