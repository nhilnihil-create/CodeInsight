#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int n, i, j = 0;
    cin >> n;
    map<string,int> x;
    for(i = 0; i<n; i++){
        string s;
        cin >> s;
        x[s]++;
        int aux = x[s];
        j = max(j,aux);
    }
    for(auto a = x.begin(); a != x.end(); a++){
        if(a->second == j){
            cout << a->first << endl;
        }
    }
    return 0;
}