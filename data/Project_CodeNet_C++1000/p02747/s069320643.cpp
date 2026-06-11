#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int i;
    if(s.size()%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    for(i = 0;i < s.size()-1;i+= 2){
       if(!(s.at(i) == 'h' && s.at(i+1) == 'i')){
           cout << "No" << endl;
           return 0;
       }
    }
    cout << "Yes" << endl;
    return 0;
}