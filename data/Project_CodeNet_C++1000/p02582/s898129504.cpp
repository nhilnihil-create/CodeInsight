#include <algorithm>
#include <iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;



int main()
{
    string s;
    cin >> s;
    int num = 0;
    int ans = 0;
    for (int i = 0; i < s.length();i++){
        if(s[i]=='R'){
            num++;
            ans = max(ans, num);
        }else{
            num = 0;
        }
    }
    cout << ans;
    return 0;
}
