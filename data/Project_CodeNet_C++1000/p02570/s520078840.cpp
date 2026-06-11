#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    float d=0, t=0, s=0;
    cin >> d >> t >> s;

    float v = d/t;

    if(v<=s){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
