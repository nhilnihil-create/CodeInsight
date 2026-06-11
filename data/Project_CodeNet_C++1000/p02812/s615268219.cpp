#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int m;
    cin>>m;
    string s;
    cin>>s;
    int n = 0;
    for(int i = 0; i < s.size() - 2; i++){
        if(s.at(i) == 'A' && s.at(i + 1) == 'B' && s.at(i + 2) == 'C'){
        n++;
        }
    }
    cout << n << endl;
}
