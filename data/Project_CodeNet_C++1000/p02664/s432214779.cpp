#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        if(s[0] == '?')
        s[0] = 'D';
        cout << s;
    }
    else if(n > 1){
    if(s[0] == '?'){
        if(s[1] == 'D')
        s[0] = 'P';
        else if(s[1] == 'P')
        s[0] = 'D';
        else if(s[1] == '?')
        s[0] = 'D';
    }
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '?'){
            s[i] = 'D';
        }
    }
    cout << s;
    }
}







