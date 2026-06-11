#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i(0); i<n; i++){
        cin >> v.at(i);
    }

    int max(0);
    for(int i(v.size()-1); i>=1; i--){
        int temp(0);
        while(v[i] <= v[i-1]){
            temp++;
            i--;
        }
        if(temp > max) max = temp;
    }
    cout << max << ENDL;

    return 0;
}