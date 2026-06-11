#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n,ans=0;
    cin >> n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    for(int i=1;i<n-1;i++){
        vector<int> aux;

        aux.push_back(v[i-1]);
        aux.push_back(v[i]);
        aux.push_back(v[i+1]);

        sort(aux.begin(),aux.end());

        if(aux[1]==v[i]){
            ans++;
        }
    }    

    cout << ans << endl;

    return 0;
}