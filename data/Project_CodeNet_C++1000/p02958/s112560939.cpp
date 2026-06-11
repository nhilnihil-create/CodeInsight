#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i]!=i+1)c++;
    }
    (c<=2)?cout << "YES\n" : cout << "NO\n" ;

    return 0;
}
