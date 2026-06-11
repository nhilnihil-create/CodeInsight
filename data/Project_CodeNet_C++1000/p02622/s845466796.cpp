#include <bits/stdc++.h>
#include <string>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Int int_fast64_t

int main()
{
    FAST_IO;

    string s,t;
    cin>>s >> t;
    Int count=0;
    for(Int i=0;i<s.length();++i) {
        if(s[i]!=t[i]) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
