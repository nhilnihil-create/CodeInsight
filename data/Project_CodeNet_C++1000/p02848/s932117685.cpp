#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int a; cin >> a;
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if(s[i]=='Z') s[i]='A';
            else s[i] += 1;
        }
        
    }
    cout << s << endl;
    
    return 0;
}