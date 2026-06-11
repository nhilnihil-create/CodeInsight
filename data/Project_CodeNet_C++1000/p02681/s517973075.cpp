#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L



void solve(){
    string a,b;

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        if(a.at(i) != b.at(i)){
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
    


}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}