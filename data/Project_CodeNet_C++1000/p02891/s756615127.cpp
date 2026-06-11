#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;


int main()
{
    string s;
    long long k;
    cin >> s;
    cin >> k;
    
    long long ans = 0;
    
    int check = 1;
    
    for (long long  i = 0;i < s.size()-1;i++){
        if (s[i] != s[i+1]) {
            check = 0;
            break;
        }
    }
    
    if (check){
        ans = (s.size()*k)/2;
    }
    else {
        long long t = 1;
        for (long long i = 0;i < s.size()-1;i++){
            if (s[i] == s[i+1]){
                t++;
            }
            else {
                ans += t/2;
                t = 1;
            }
        }
        ans += t/2;
        
        if (s[0] == s[s.size()-1]){
            long long sta = 1;
            long long end = 1;
            for (long long i = 0;i < s.size()-1;i++){
                if (s[i] != s[i+1]) break;
                sta++;
            }
            for (long long i = s.size()-1;i >= 1;i--){
                if (s[i] != s[i-1]) break;
                end++;
            }
            ans = ans*k-(sta/2+end/2-(sta+end)/2)*(k-1);
        }
        else {
            ans *= k;
        }
    }
    
    cout << ans << endl;
}
