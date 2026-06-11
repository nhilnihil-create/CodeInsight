#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int MOD = 1e9+7;
const int N = 5*1e5;



int main(){
    AC
    string s;
    cin>>s;
    switch(s[s.size()-1]){
        case '2':
        case '4':
        case '5':
        case '7':
        case '9': 
            cout<<"hon"<<endl;
            break;
        case '3':
            cout<<"bon"<<endl;
            break;
        default:
            cout<<"pon"<<endl;
            break;
    }
}